echo [Setting Development Environment]


set SOLIDMCP_SOLUTION=S:\Workspace\Build\Solutions\SolidMCP\MySolution.sln
if /I .%1 == .     (call "%VS90COMNTOOLS%vsvars32" & devenv   %SOLIDMCP_SOLUTION%)
if /I .%1 == .dev8 (call "%VS80COMNTOOLS%vsvars32" & devenv   %SOLIDMCP_SOLUTION%)
if /I .%1 == .dev9 (call "%VS80COMNTOOLS%vsvars32" & devenv   %SOLIDMCP_SOLUTION%)