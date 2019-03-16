# First stage is the build environment
FROM matiasragnar/dockermxp
MAINTAINER Kleiner Matias <kleiner.matias@gmail.com>

ENTRYPOINT service ssh restart && bash /config.sh && netconfd --module=cli-mxp --log-level="debug4" --target=running --superuser=root --with-startup=true && bash

