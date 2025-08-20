return {
	{
		"echasnovski/mini.nvim",
		version = "*",
		config = function()
			require("mini.files").setup({})
			require("mini.pairs").setup({})
		end,
	},
}
