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
  libncurses5-dev 

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
  wget http://archive.ubuntu.com/ubuntu/pool/main/z/zlib/zlib_1.2.8.dfsg.orig.tar.gz && \
  tar -xzvf zlib_1.2.8.dfsg.orig.tar.gz && \
  cd zlib-1.2.8 && \
  ./configure --static --prefix=/root/usrapp && \
  make -j4 && \
  make install

RUN \
  cd ~ && \
  wget http://archive.ubuntu.com/ubuntu/pool/main/libx/libxml2/libxml2_2.9.3+dfsg1.orig.tar.xz && \
  tar -xvf libxml2_2.9.3+dfsg1.orig.tar.xz && \
  cd ~/libxml2-2.9.3 && \ 
  ./configure --prefix=/root/usrapp && \ 
  make -j4 && \
  make install

# openssl
RUN \
  cd ~ && \
  git clone https://github.com/openssl/openssl.git

RUN \
  cd ~/openssl && \
  ./Configure linux-generic32 -DOPENSSL_NO_HEARTBEATS --prefix=/root/usrapp/ --openssldir=/root/usrapp/ && \
  make -j4 && \
  make install_sw

# libssh2

RUN \
  git clone https://github.com/libssh2/libssh2.git && \
  cd libssh2 && \
  rm -r -f /usr/lib/x86_64-linux-gnu/libssl.so && \
  rm -r -f /usr/lib/x86_64-linux-gnu/libcrypto.so && \
  rm -r -f /usr/lib/x86_64-linux-gnu/libssl.a && \
  rm -r -f /usr/lib/x86_64-linux-gnu/libcrypto.a && \
  rm -r -f /root/usrapp/lib/libz.a && \
  ./buildconf && \
  ./configure CFLAGS='-O2' CXXFLAGS='-O2' --prefix=/root/usrapp && \
  cp -r -f /root/usrapp/* /root/nios2-compiler/sourceryg++-2018.05/nios2-linux-gnu/libc/usr/ && \
  make -j4 && \
  make install

#RUN \
#  cd ~ && \
#  wget http://ftp.gnu.org/gnu/readline/readline-6.2.tar.gz && \
#  tar -pxzf readline-6.2.tar.gz && \
#  wget http://lfs-matrix.net/patches/downloads/readline/readline-6.2-fixes-1.patch && \
#  cd readline-6.2/ && \
#  patch -Np1 -i ../readline-6.2-fixes-1.patch && \
#  ./configure CFLAGS='-O2' CXXFLAGS='-O2' --prefix=/root/usrapp && \
#  make -j4 && \
#  make install


RUN \
  cd ~ && \
  wget http://archive.ubuntu.com/ubuntu/pool/main/z/zlib/zlib_1.2.8.dfsg.orig.tar.gz && \
  tar -xzvf zlib_1.2.8.dfsg.orig.tar.gz && \
  cd zlib-1.2.8 && \
  ./configure --static --prefix=/root/usrapp && \
  make -j4 && \
  make install

RUN \
  cd ~/yuma123-git && \
  ldconfig && \
  cp -r -f /root/usrapp/* /usr/

RUN \
  cd ~/yuma123-git && \
  autoreconf -i -f && \
  ./configure --disable-shared --enable-static LDFLAGS="-lncurses" CFLAGS='-lreadline -lncurses -O2' CXXFLAGS='-O2' --prefix=/root/usrapp && \  
  make -j4 && \
  make install

ENV EDITOR vim

CMD ["/bin/bash"]
