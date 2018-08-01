FROM ubuntu:16.04

RUN \
	apt-get update && apt-get install -y \
	git \
	autoconf \
	gcc \
	libtool \
	libxml2-dev \
	libssh2-1-dev \
	make \
	libncurses5-dev \
	zlib1g-dev \
	libreadline-dev \
	openssh-server \
	libssl-dev \
	vim \
	nano

RUN \
	cd ~ && \
	git clone git://git.code.sf.net/p/yuma123/git yuma123-git && \
	cd yuma123-git && \
	autoreconf -i -f && \
	./configure CFLAGS='-g -O0' CXXFLAGS='-g -O0' --prefix=/usr && \
	make -j4 && \
	make install

RUN \
	sed -i '1i Subsystem netconf /usr/sbin/netconf-subsystem' /etc/ssh/sshd_config && \
	sed -i '1i Port 830' /etc/ssh/sshd_config && \
	sed -i '1i #Las siguientes dos lineas son para yuma.' /etc/ssh/sshd_config && \
	sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/g' /etc/ssh/sshd_config && \
	echo "root:fulgor" | chpasswd

ENTRYPOINT service ssh restart && bash

# netconfd &
# yangcli --user=root --server=localhost --pass=fulgor

#docker network create --subnet=172.18.0.0/16 mynet123 
#docker run --net mynet123 --ip 172.18.0.22 -it fulgor/yuma123 bash 
