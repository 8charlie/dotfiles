export TERMINAL="kitty"
export EDITOR="nvim"
export VISUAL="${EDITOR}"
export PDFVIEWER="zathura"

# plugins
source ~/.config/zsh/zsh-autosuggestions/zsh-autosuggestions.zsh
source ~/.config/zsh/you-should-use/you-should-use.plugin.zsh
source ~/.config/zsh/zsh-vi-mode/zsh-vi-mode.zsh
source ~/.config/zsh/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh 

# history
HISTFILE=~/.zsh_history
HISTSIZE=10000
SAVEHIST=10000
setopt SHARE_HISTORY
