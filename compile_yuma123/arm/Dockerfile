FROM ubuntu:16.04

RUN \
  apt-get update && apt-get install -y \
  git \
  cmake \
  build-essential \
  vim \
  autoconf \
  unzip \
  wget \
  gcc \
  make \
  nano \
  libtool \
  libreadline-dev \
  libncurses5-dev \
  gcc-multilib \
  lib32z1

RUN \
  mkdir ~/usrapp && \
  mkdir ~/usrutils

WORKDIR /root/

# arm compiler
RUN \
      cd ~ && \
      git clone https://github.com/raspberrypi/tools.git

ENV PATH="$PATH:/root/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin"


RUN \
  cd ~ && \
  git clone git://git.code.sf.net/p/yuma123/git yuma123-git 

RUN \
  cd ~ && \
  wget http://archive.ubuntu.com/ubuntu/pool/main/z/zlib/zlib_1.2.8.dfsg.orig.tar.gz && \
  tar -xzvf zlib_1.2.8.dfsg.orig.tar.gz && \
  cd zlib-1.2.8 && \
  mkdir build && \
  cd build && \
  CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ cmake -DCMAKE_INSTALL_PREFIX:PATH=/root/usrapp .. && \
  make  -j4 && \
  make install

RUN \
  cd ~ && \
  wget http://archive.ubuntu.com/ubuntu/pool/main/libx/libxml2/libxml2_2.9.3+dfsg1.orig.tar.xz && \
  tar -xvf libxml2_2.9.3+dfsg1.orig.tar.xz && \
  cd ~/libxml2-2.9.3 && \
  ./configure --host=arm-none-linux-gnueabi CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ --prefix=/root/usrapp && \ 
  CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ make -j4 && \
  make install

# openssl
RUN \
  cd ~ && \
  git clone https://github.com/openssl/openssl.git

RUN \
  cd ~/openssl && \
  git checkout OpenSSL_1_0_2-stable && \
  ./Configure linux-generic32 shared -DOPENSSL_NO_HEARTBEATS --prefix=/root/usrapp/ --openssldir=/root/usrapp/ && \
  make CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ MAKEDEPPROG=arm-linux-gnueabihf-gcc PROCESSOR=ARM -j4 && \
  make install_sw

# libssh2

RUN \
  git clone https://github.com/libssh2/libssh2.git && \
  cd libssh2 && \
  ./buildconf && \
  ./configure --host=arm-none-linux-gnueabi CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ CFLAGS='-O2' CXXFLAGS='-O2' --prefix=/root/usrapp && \
  cp -r -f /root/usrapp/* /root/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/ && \
  make -j4 && \
  make install

RUN \
  cd ~ && \
  wget http://ftp.gnu.org/gnu/readline/readline-6.2.tar.gz && \
  tar -pxzf readline-6.2.tar.gz && \
  wget http://lfs-matrix.net/patches/downloads/readline/readline-6.2-fixes-1.patch && \
  cd readline-6.2/ && \
  patch -Np1 -i ../readline-6.2-fixes-1.patch && \
  ./configure --host=arm-none-linux-gnueabi CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ --enable-shared CFLAGS='-O2' CXXFLAGS='-O2' --prefix=/root/usrapp && \
  make -j4 && \
  make install


RUN \
  cd ~/yuma123-git && \
  ldconfig && \
  cp -r -f /root/usrapp/* /usr/

RUN \
  wget http://ftp.gnu.org/pub/gnu/ncurses/ncurses-5.7.tar.gz && \
  tar xzf ncurses-5.7.tar.gz && \
  cd ncurses-5.7 && \
  ./configure --host=arm-none-linux-gnueabi CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ --with-shared --without-debug --without-ada --enable-overwrite --prefix=/root/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr

RUN cd ncurses-5.7; make -j4; make install; exit 0

RUN \
  cp -R -f /root/usrapp/* /root/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr && \
  cd ~/yuma123-git && \
  autoreconf -i -f && \
  ./configure --host=arm-none-linux-gnueabi CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ --enable-shared --enable-static  LDFLAGS=-L/root/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/lib LDFLAGS="-lncurses" CFLAGS='-O2' CXXFLAGS='-O2' --prefix=/root/usrapp && \
  make -j4 && \
  make install




ENV EDITOR vim

CMD ["/bin/bash"]
