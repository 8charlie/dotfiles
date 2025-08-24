if status is-interactive
    # Commands to run in interactive sessions can go here
end

fish_vi_key_bindings
set fish_cursor_default block
set fish_cursor_insert line

alias vim=nvim
alias 'dnfi'='sudo dnf install -y'
alias 'dnfu'='sudo dnf update --refresh -y && flatpak update'

set -U fish_greeting ""
set -x PATH /opt/homebrew/bin $PATH
