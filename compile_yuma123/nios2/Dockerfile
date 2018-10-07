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
  libxml2-dev

RUN \
  mkdir ~/usrapp && \
  mkdir ~/usrutils && \
  mkdir ~/nios2-compiler

WORKDIR /root/

# nios2 compiler  
RUN \
  wget https://sourcery.mentor.com/GNUToolchain/package15404/public/nios2-linux-gnu/sourceryg++-2018.05-5-nios2-linux-gnu-i686-pc-linux-gnu.tar.bz2 && \
  tar -jxvf sourceryg++-2018.05-5-nios2-linux-gnu-i686-pc-linux-gnu.tar.bz2 -C /root/nios2-compiler

ENV PATH="$PATH:/root/nios2-compiler/sourceryg++-2018.05/bin"

RUN \
  cd ~ && \
  git clone git://git.code.sf.net/p/yuma123/git yuma123-git 

RUN \
  cd ~ && \
  export CFLAGS=-O3 && \
  wget http://archive.ubuntu.com/ubuntu/pool/main/z/zlib/zlib_1.2.8.dfsg.orig.tar.gz && \
  tar -xzvf zlib_1.2.8.dfsg.orig.tar.gz && \
  cd zlib-1.2.8 && \
  mkdir build && \
  cd build && \
  CC=nios2-linux-gnu-gcc CXX=nios2-linux-gnu-g++ cmake CMAKE_C_FLAGS=-O3 -DCMAKE_INSTALL_PREFIX:PATH=/root/usrapp .. && \
  make VERBOSE=1 -j4 && \
  make install

RUN \
  cd ~ && \
  wget http://http.debian.net/debian/pool/main/libx/libxml2/libxml2_2.9.4+dfsg1.orig.tar.xz && \
  tar -xvf libxml2_2.9.4+dfsg1.orig.tar.xz && \
  cd ~/libxml2-2.9.4 && \
  export CFLAGS=-O3 && \
  ./configure --host=nios2-linux CC=nios2-linux-gnu-gcc CXX=nios2-linux-gnu-g++ --prefix=/root/usrapp && \ 
  CC=nios2-linux-gnu-gcc CXX=nios2-linux-gnu-g++ CFLAGS='-O3' CXXFLAGS='-O3' VERBOSE=1 make -j4 && \
  make install

# openssl
RUN \
  cd ~ && \
  git clone https://github.com/openssl/openssl.git

RUN \
  cd ~/openssl && \
  git checkout OpenSSL_1_0_2-stable && \
  ./Configure linux-generic32 shared -DOPENSSL_NO_HEARTBEATS --prefix=/root/usrapp/ --openssldir=/root/usrapp/ && \
  make CC=nios2-linux-gnu-gcc CXX=nios2-linux-gnu-g++ MAKEDEPPROG=nios2-linux-gnu-gcc PROCESSOR=NIOS2 -j4 && \
  make install_sw

# libssh2

RUN \
  git clone https://github.com/libssh2/libssh2.git && \
  cd libssh2 && \
  ./buildconf && \
  ./configure --host=nios2-linux CC=nios2-linux-gnu-gcc CXX=nios2-linux-gnu-g++ CFLAGS='-O3' CXXFLAGS='-O3' --prefix=/root/usrapp && \
  cp -r -f /root/usrapp/* /root/nios2-compiler/sourceryg++-2018.05/nios2-linux-gnu/libc/usr/ && \
  make VERBOSE=1 -j4 && \
  make install

RUN \
  cd ~ && \
  wget http://ftp.gnu.org/gnu/readline/readline-6.2.tar.gz && \
  tar -pxzf readline-6.2.tar.gz && \
  wget http://lfs-matrix.net/patches/downloads/readline/readline-6.2-fixes-1.patch && \
  cd readline-6.2/ && \
  patch -Np1 -i ../readline-6.2-fixes-1.patch && \
  ./configure --host=nios2-linux CC=nios2-linux-gnu-gcc CXX=nios2-linux-gnu-g++ CFLAGS='-O3' CXXFLAGS='-O3' --prefix=/root/usrapp && \
  make VERBOSE=1 -j4 && \
  make install


RUN \
  cd ~/yuma123-git && \
  ldconfig && \
  cp -r -f /root/usrapp/* /usr/

RUN \
  wget http://ftp.gnu.org/pub/gnu/ncurses/ncurses-5.7.tar.gz && \
  tar xzf ncurses-5.7.tar.gz && \
  cd ncurses-5.7 && \
  ./configure --host=nios2-linux CC=nios2-linux-gnu-gcc CXX=nios2-linux-gnu-g++ CFLAGS='-O3' CXXFLAGS='-O3' --with-shared --without-debug --without-ada --enable-overwrite --prefix=/root/nios2-compiler/sourceryg++-2018.05/nios2-linux-gnu/libc/

RUN cd ncurses-5.7; make VERBOSE=1 -j4; make install; exit 0

RUN \
  cp -R -f /root/usrapp/* /root/nios2-compiler/sourceryg++-2018.05/nios2-linux-gnu/libc/usr/ && \
  cd ~/yuma123-git && \
  autoreconf -i -f && \
  ./configure --host=nios2-linux CC=nios2-linux-gnu-gcc CXX=nios2-linux-gnu-g++ --enable-shared --enable-static  LDFLAGS=-L/root/nios2-compiler/sourceryg++-2018.05/nios2-linux-gnu/libc/usr/lib LDFLAGS="-lncurses" CFLAGS='-O3' CXXFLAGS='-O3' --prefix=/root/usrapp && \
  make VERBOSE=1 -j4 && \
  make install



ENV EDITOR vim

CMD ["/bin/bash"]
