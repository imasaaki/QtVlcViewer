#pragma once

class QString;

typedef void (*CallbackReceivedFrame)(void*, char*, int, int);

class VideoFrameGetter
{
public:
    VideoFrameGetter(void* pParent);
    ~VideoFrameGetter() = default;
    VideoFrameGetter(const VideoFrameGetter& in_src) = delete;
    void start(const QString& url, CallbackReceivedFrame callbackReceivedFrame);
    void stop();
private:
    void* pParent;
};
