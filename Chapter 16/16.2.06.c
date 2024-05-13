struct time {
    int hours;
    int minutes;
    int seconds;
};

struct time split_time(long total_seconds)
{
    struct time t;

    t.hours = total_seconds / (60 * 60);
    total_seconds %= 60 * 60;
    t.minutes = total_seconds / 60;
    total_seconds %= 60;
    t.seconds = total_seconds;

    return t;
}