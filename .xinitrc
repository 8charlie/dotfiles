setxkbmap -option caps:ctrl_modifier
xcape -e 'Caps_Lock=Escape'
feh --bg-scale /home/kyrii/Pictures/wallpaper/grey_lain_wallpaper.jpg
xset r rate 300 50
xrandr --output DP-2 --mode 2560x1440 --rate 270
picom -b

#exec i3

exec dwmblocks &
exec dwm

#exec awesome

#sxhkd &
#polybar &
#exec bspwm
