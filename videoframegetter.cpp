#include "videoframegetter.h"
#include <vlc/vlc.h>
#include <QString>
#include <thread>
#include <chrono>
VideoFrameGetter::VideoFrameGetter(void* apParent):
    pParent(apParent)
{}
void VideoFrameGetter::start(const QString& url, CallbackReceivedFrame callbackReceivedFrame)
{
    libvlc_instance_t * inst;
         libvlc_media_player_t *mp;
         libvlc_media_t *m;

         /* Load the VLC engine */
         inst = libvlc_new (0, NULL);

         /* Create a new item */
         m = libvlc_media_new_location (inst, url.toStdString().c_str());
         //m = libvlc_media_new_path (inst, "/path/to/test.mov");

         /* Create a media player playing environement */
         mp = libvlc_media_player_new_from_media (m);

         /* No need to keep the media now */
         libvlc_media_release (m);

         /* play the media_player */
         libvlc_media_player_play (mp);
         std::this_thread::sleep_for(std::chrono::milliseconds(10000));

         /* Stop playing */
         libvlc_media_player_stop (mp);

         /* Free the media_player */
         libvlc_media_player_release (mp);

         libvlc_release (inst);
}
void VideoFrameGetter::stop()
{}
