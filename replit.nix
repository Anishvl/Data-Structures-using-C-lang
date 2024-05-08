{ pkgs }: {
	deps = [
		pkgs.sudo
  pkgs.nano
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}