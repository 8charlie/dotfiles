-- set leader key
vim.g.mapleader = " "

-- Bootstrap lazy.nvim
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not (vim.fn.systemlist("git -C " .. lazypath .. " rev-parse --is-inside-work-tree")[1] == "true") then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "--branch=stable",
    "https://github.com/folke/lazy.nvim.git",
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

-- set plugins folder
require("lazy").setup("plugins")
 
-- plugin customizations
vim.cmd.colorscheme('gruvbox')
vim.api.nvim_set_hl(0, "Normal", { bg = "NONE" })

-- sets tab to 4 spaces
-- vim.o.expandtab = false
-- vim.o.tabstop = 4
-- vim.o.shiftwidth = 4

-- search alterations
vim.opt.ignorecase = true -- search is case insensitive
vim.opt.smartcase = true -- search matters if capital letter
vim.opt.inccommand = 'split' -- previews what youll replace stuff with during replace

-- start of keybinds
local keyset = vim.keymap.set
vim.opt.splitbelow = true -- split windows below
vim.opt.splitright = true -- split windows right

-- non-plugins binds
vim.keymap.set("n", "<leader>dv", vim.cmd.Ex)
keyset("n", "<leader>ex", ":Ex<cr>")
keyset("n", "<leader>rc", ":%s/<C-r><C-w>//g<Left><Left>") -- replace under cursor
keyset("n", "<down>", ":resize +2<cr>") -- resizes windows
keyset("n", "<up>", ":resize -2<cr>") 
keyset("n", "<right>", ":vertical resize +2<cr>") 
keyset("n", "<left>", ":vertical resize -2<cr>")
keyset("n", ",h", "<c-w>h") -- switch between windows
keyset("n", ",j", "<c-w>j")
keyset("n", ",k", "<c-w>k")
keyset("n", ",l", "<c-w>l")
keyset("n", "<TAB>", ":bnext<cr>") -- next buffer
keyset("n", "<S-TAB>", ":bprevious<cr>") -- previous buffer
keyset("n", "<leader>bb", ":Telescope buffers<cr>") -- show all opened buffers in telescope
keyset("n", "<C-d>", "<C-d>zz") -- centers screen after ctrl d
keyset("n", "<C-u>", "<C-u>zz") -- centers screen after ctrl u


-- telescope binds
keyset('n', '<leader>ff', ':Telescope find_files<cr>')
keyset('n', '<leader>fh', function()
	require('telescope.builtin').find_files({ hidden = true })
end )
keyset('n', '<leader>fg', ':Telescope live_grep<cr>')

