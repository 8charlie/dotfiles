//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/    /*Command*/        /*Update Interval*/    /*Update Signal*/


//  {" " , "curl -s 'wttr.in/Tashkent?format=%t'", 300, 0},

//	{"  ┇  󰂎 ", "echo \"$(cat /sys/class/power_supply/BAT1/capacity)%\"", 15, 0}, // battery symbol was 
	{"󰕾 ", "echo $(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}') ", 10, 0},
	{" " , "date '+%d.%m'", 60, 0},
	{" ", "date '+%H:%M  '", 5, 0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = "  ┇  ";
static unsigned int delimLen = 7;
