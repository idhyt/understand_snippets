-- Do Not Edit This File.
-- [32] = default; [33] = line number; [34] = brace highlight; [35] = unmatched brace
return {
  common = {
    style = {
      caret = {
        back = "#e9e9e9"
      },
      comment = {
        fore = "#0000ff",
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
        fore = "#cc0000"
      },
      error = {
        back = "#ff0000",
        eolfilled = true,
        fore = "#ffff00"
      },
      find = {
        back = "#ff0000"
      },
      foldMargin = {
        back = "#c0c0c0"
      },
      identifier = {

      },
      inactive = {
        back = "#ffdddd",
        eolfilled = true
      },
      keyword = {
        bold = true,
        fore = "#000080"
      },
      label = {
        fore = "#800000"
      },
      number = {
        fore = "#008080"
      },
      operator = {
        bold = true
      },
      preprocessor = {
        bold = true,
        fore = "#008000"
      },
      ref = {
        back = "#00ff00"
      },
      selection = {
        back = "#ccccff",
        eolfilled = true
      },
      singleQuotedString = {
        fore = "#800080"
      },
      unclosedDoubleQuotedString = {
        back = "#e0c0e0",
        eolfilled = true
      },
      unclosedSingleQuotedString = {
        back = "#e0c0e0",
        eolfilled = true
      },
      whitespace = {
        fore = "#808080"
      }
    }
  },
  style = {
    [32] = {
      back = "#ffffff",
      fore = "#000000"
    },
    [33] = {
      back = "#a0a0a0"
    },
    [34] = {
      back = "#00ff00",
      bold = true
    },
    [35] = {
      back = "#ff0000",
      bold = true
    }
  },
  udb = {
    style = {
      ada = {
        globalVariableNames = {
          bold = true,
          fore = "#003366"
        },
        localVariableNames = {
          fore = "#003366",
          italic = true
        },
        subprogramNames = {
          fore = "#800000"
        },
        typeNames = {
          underline = true
        }
      },
      cs = {
        classNames = {
          underline = true
        },
        enumeratorNames = {
          fore = "#0080ff"
        },
        methodNames = {
          fore = "#800000"
        },
        typeNames = {
          underline = true
        }
      },
      cxx = {
        classNames = {
          underline = true
        },
        enumeratorNames = {
          fore = "#0080ff"
        },
        functionNames = {
          fore = "#800000"
        },
        globalVariableNames = {
          bold = true,
          fore = "#003366"
        },
        localVariableNames = {
          fore = "#003366"
        },
        macroNames = {
          bold = true,
          fore = "#800080"
        },
        memberFunctionNames = {
          fore = "#800000",
          italic = true
        },
        memberVariableNames = {
          fore = "#003366",
          italic = true
        },
        parameterNames = {
          fore = "#003366"
        },
        typeNames = {
          underline = true
        },
        virtualFunctionNames = {
          bold = true,
          fore = "#800000",
          italic = true
        }
      },
      fortran = {
        subprogramNames = {
          fore = "#800000"
        },
        typeNames = {
          underline = true
        }
      },
      java = {
        classNames = {
          underline = true
        },
        interfaceNames = {
          underline = true
        },
        methodNames = {
          fore = "#800000"
        }
      },
      jovial = {
        subroutineNames = {
          fore = "#800000"
        },
        typeNames = {
          underline = true
        }
      },
      pascal = {
        routineNames = {
          fore = "#800000"
        },
        typeNames = {
          underline = true
        }
      },
      python = {
        classNames = {
          underline = true
        },
        functionNames = {
          fore = "#800000"
        }
      },
      vhdl = {
        processNames = {
          fore = "#800000"
        },
        subprogramNames = {
          fore = "#800000"
        },
        typeNames = {
          underline = true
        }
      }
    }
  }
}