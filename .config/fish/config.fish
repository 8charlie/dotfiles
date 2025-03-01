if status is-interactive
    # Commands to run in interactive sessions can go here
end



fish_vi_key_bindings
set fish_cursor_default block
set fish_cursor_insert line


# startx after login for tty1
if test (tty) = "/dev/tty1"
    startx
end


starship init fish | source

set -U fish_greeting ""
