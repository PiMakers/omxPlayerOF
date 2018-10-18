#pragma once

#include "ofMain.h"
#include "ofxomxPlayerOF.h"


class OmxPubHubPlayer : public ofThread {

public:

    OmxPubHubPlayer ();
    ~OmxPubHubPlayer ();

    int omxPlayerCli (int argc, char** argv);
    ///(int argc, char *argv[]);
    int exit();

    OMXControl      m_omxcontrol;
    Keyboard       *m_keyboard;
 /****************/
    std::string     m_filename;
    bool            m_dump_format;
    bool            m_dump_format_exit;
    uint32_t        m_blank_background;

    // amount of time file/network operation can stall for before timing out
    float           m_timeout = 10.0f;
    int             m_orientation = -1; // unset
    float           m_fps; // unset

    std::string     m_cookie;
    std::string     m_user_agent;
    std::string     m_lavfdopts;
    std::string     m_avdict;

private:

    typedef enum {
        CONF_FLAGS_FORMAT_NONE,
        CONF_FLAGS_FORMAT_SBS,
        CONF_FLAGS_FORMAT_TB,
        CONF_FLAGS_FORMAT_FP
        } FORMAT_3D_T;

    enum PCMChannels  *m_pChannelMap;

    long            m_Volume;
    long            m_Amplification;
    bool            m_NativeDeinterlace;
    bool            m_HWDecode;
    bool            m_osd;
    bool            m_no_keys;
    std::string     m_external_subtitles_path;
    bool            m_has_external_subtitles;
    std::string     m_font_path = "/usr/share/fonts/truetype/freefont/FreeSans.ttf";
    std::string     m_italic_font_path = "/usr/share/fonts/truetype/freefont/FreeSansOblique.ttf";
    std::string     m_dbus_name = "org.mpris.MediaPlayer2.omxplayer";
    bool            m_asked_for_font;
    bool            m_asked_for_italic_font;
    float           m_font_size = 0.055f;
    bool            m_centered;
    bool            m_ghost_box = true;
    unsigned int    m_subtitle_lines = 3;
    bool            m_Pause;
    OMXReader       m_omx_reader;
    int             m_audio_index_use;
    OMXClock       *m_av_clock;    // = NULL;

    OMXAudioConfig  m_config_audio;
    OMXVideoConfig  m_config_video;
    OMXPacket      *m_omx_pkt = NULL;  //!!!!!!!!!!!!!!!
    bool            m_no_hdmi_clock_sync;
    bool            m_stop;
    int             m_subtitle_index = -1;
    DllBcmHost      m_BcmHost;
    OMXPlayerVideo  m_player_video;
    OMXPlayerAudio  m_player_audio;
    OMXPlayerSubtitles  m_player_subtitles;
    int             m_tv_show_info;
    bool            m_has_video;
    bool            m_has_audio;
    bool            m_has_subtitle;
    bool            m_gen_log;
    bool            m_loop;

    enum {
        ERROR=-1,
        SUCCESS,
        ONEBYTE
        };

protected:

    CRBP        g_RBP;
    COMXCore    g_OMX;

    bool                m_stats;
    bool                m_refresh;
    bool                m_send_eos;
    TV_DISPLAY_STATE_T  tv_state;
    FORMAT_3D_T         m_3d = CONF_FLAGS_FORMAT_NONE;

private:

  #define S(x) (int)(DVD_PLAYSPEED_NORMAL*(x))
  int playspeeds[20] = {S(0), S(1/16.0), S(1/8.0), S(1/4.0), S(1/2.0), S(0.975), S(1.0), S(1.125), S(-32.0), S(-16.0), S(-8.0), S(-4), S(-2), S(-1), S(1), S(2.0), S(4.0), S(8.0), S(16.0), S(32.0)};
  const int playspeed_slow_min = 0, playspeed_slow_max = 7, playspeed_rew_max = 8, playspeed_rew_min = 13, playspeed_normal = 14, playspeed_ff_min = 15, playspeed_ff_max = 19;
  int playspeed_current = playspeed_normal;
  double m_last_check_time = 0.0; ///*H Moved to root because Threaded func.
  float m_latency = 0.0f;

  int           control_err= -1;
  bool          m_seek_flush        = false;
  double        startpts            = 0;
  bool          m_chapter_seek      = false;
  double        m_incr              = 0;
  bool          idle                = false;
  float         m_threshold         = -1.0f; // amount of audio/video required to come out of buffering
  double        last_seek_pos       = 0;
  bool          sentStarted         = false;
  bool          m_packet_after_seek = false;
  double        m_loop_from         = 0;

///    vector<int> signals;

///    void sig_handler(int s);
    void threadedFunction();
    void print_usage();
    void print_keybindings();
    void print_version();
    void PrintSubtitleInfo();
    void FlushStreams(double pts);
    void SetSpeed(int iSpeed);
    float get_display_aspect_ratio(HDMI_ASPECT_T aspect);
    float get_display_aspect_ratio(SDTV_ASPECT_T aspect);
    static void CallbackTvServiceCallback(void *userdata, uint32_t reason, uint32_t param1, uint32_t param2);
    void SetVideoMode(int width, int height, int fpsrate, int fpsscale, FORMAT_3D_T is3d);
    bool Exists(const std::string& path);
    bool IsURL(const std::string& str);
    bool IsPipe(const std::string& str);
    int get_mem_gpu(void);
    void blank_background(uint32_t rgba);
};
