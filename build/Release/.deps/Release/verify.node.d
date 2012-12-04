cmd_Release/verify.node := ln -f "Release/obj.target/verify.node" "Release/verify.node" 2>/dev/null || (rm -rf "Release/verify.node" && cp -af "Release/obj.target/verify.node" "Release/verify.node")
