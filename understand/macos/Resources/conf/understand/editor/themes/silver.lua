-- Do Not Edit This File.
-- [32] = default; [33] = line number; [34] = brace highlight; [35] = unmatched brace
return {
	common = {
		style = {
			caret = {
				back = "#d9d9d9"
			},
			comment = {
				fore = "#560ce8",
				italic = true
			},
			docComment = {
				fore = "#993300",
				italic = true
			},
			docKeyword = {
				bold = true,
				fore = "#663300",
				italic = true
			},
			doubleQuotedString = {
				fore = "#0dff77"
			},
			error = {
				back = "#ff0000",
				eolfilled = true,
				fore = "#ffff00"
			},
			find = {
				back = "#1a034b"
			},
			foldMargin = {
				back = "#a6a6a6"
			},
			identifier = {

			},
			inactive = {
				back = "#c58a8a",
				eolfilled = true
			},
			keyword = {
				bold = true,
				fore = "#ff2e00"
			},
			label = {
				fore = "#800000"
			},
			number = {
				fore = "#0dff77"
			},
			operator = {
				bold = true
			},
			preprocessor = {
				bold = true,
				fore = "#180fe8"
			},
			ref = {
				back = "#00ff00"
			},
			selection = {
				back = "#9d9d9d"
			},
			singleQuotedString = {
				fore = "#0dff77"
			},
			unclosedDoubleQuotedString = {
				back = "#c58a8a",
				eolfilled = true
			},
			unclosedSingleQuotedString = {
				back = "#c58a8a",
				eolfilled = true
			},
			whitespace = {
				fore = "#808080"
			}
		}
	},
	style = {
		[32] = {
			back = "#b9b9b9",
			fore = "#000000"
		},
		[33] = {
			back = "#7e7e7e"
		},
		[34] = {
			back = "#08d561",
			bold = true
		},
		[35] = {
			back = "#ff0f00",
			bold = true
		}
	},
	udb = {
		style = {
			ada = {
				globalVariableNames = {
					bold = true,
					fore = "#9207aa",
					underline = true
				},
				localVariableNames = {
					fore = "#9207aa",
					italic = true
				},
				packageNames = {
					fore = "#ff007f"
				},
				subprogramNames = {
					fore = "#aa5500"
				}
			},
			cs = {
				classNames = {
					fore = "#ff007f"
				},
				methodNames = {
					fore = "#aa5500"
				}
			},
			cxx = {
				classNames = {
					fore = "#ff007f"
				},
				functionNames = {
					fore = "#aa5500"
				},
				globalVariableNames = {
					bold = true,
					fore = "#9207aa",
					underline = true
				},
				localVariableNames = {
					fore = "#9207aa",
					italic = true
				}
			},
			fortran = {
				subprogramNames = {
					fore = "#aa5500"
				}
			},
			java = {
				classNames = {
					fore = "#ff007f"
				},
				methodNames = {
					fore = "#aa5500"
				}
			},
			jovial = {
				subroutineNames = {
					fore = "#aa5500"
				}
			},
			pascal = {
				routineNames = {
					fore = "#aa5500"
				}
			},
			python = {
				classNames = {
					fore = "#ff007f"
				},
				functionNames = {
					fore = "#aa5500"
				}
			},
			vhdl = {
				subprogramNames = {
					fore = "#aa5500"
				}
			}
		}
	}
}