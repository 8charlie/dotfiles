setxkbmap -option caps:ctrl_modifier
xcape -e 'Caps_Lock=Escape'
feh --bg-scale ~/Pictures/wallpaper/grey_lain_wallpaper.jpg
xset r rate 300 50
xrandr --output DP-2 --mode 1920x1080 --rate 240
picom -b

exec i3

#exec dwmblocks &
#exec dwm

#skhd &
#polybar &
#exec bspwm
