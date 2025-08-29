return {
	{
		"neovim/nvim-lspconfig",
	},
	{
		"williamboman/mason.nvim",
		opts = {},
	},
	{
		"mason-org/mason-lspconfig.nvim",
		dependencies = { "nvim-lspconfig" },
		opts = {
			ensure_installed = { "lua_ls", "clangd" },
		},
	},
}
