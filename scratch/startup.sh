
# Startup script for projects

# Make a place for your projects
sudo mkdir -p /projects/{1,2,3,4}
sudo chmod -R 777 /projects

# Install packages (proceed with any prompts; the default is likely file)
sudo apt-get update
sudo apt-get -y dist-upgrade
sudo apt-get install -y vim emacs htop tmux tree time curl
sudo apt-get install -y gcc gcc-doc gdb make ranger tree
sudo apt-get install -y valgrind strace glances
sudo apt-get install -y linux-tools-common linux-tools-generic
sudo apt-get install -y linux-tools-`uname -r`
sudo apt-get install -y libcap-dev
sudo apt-get install -y libacl1-dev build-essential libffi-dev
sudo apt-get install -y bats zlib1g-dev zlib1g-dbg 

sudo apt-get install -y python3 ipython3 python3-pip
sudo apt-get install -y python3-tk ssh evince
pip3 install --upgrade pip
python3 -m pip install --user pip pandas numpy matplotlib

cd /projects
wget http://man7.org/tlpi/code/download/tlpi-200106-dist.tar.gz
tar xvzf tlpi-200106-dist.tar.gz
cd tlpi-dist/
make
