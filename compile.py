import sys
sys.dont_write_bytecode = True
from pathlib import Path
import subprocess
import shutil

############################################################
# linux only for now
bin_name = "f"
src_path = "./src/"
build_path = "./build/"
############################################################

def getCFiles() -> list[str]:
    return [str(p) for p in Path(src_path).glob("*.cpp")]

def compile():
    build_dir = Path(build_path)

    if build_dir.exists():
        shutil.rmtree(build_dir)

    build_dir.mkdir(parents=True, exist_ok=True)

    out = str(build_dir / bin_name)
    subprocess.run(["gcc", *getCFiles(), "-o", out], check=True)

compile()

# TODO: change the rm build thing to a subprocess command rather than the weird module that is here
