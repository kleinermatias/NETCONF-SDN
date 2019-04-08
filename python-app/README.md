GUI NETCONF ASYNC

Kleiner Matias 22/03/2019


===========

Asynchronous flask communication with web page. 

This repository is a sample flask application that updates a webpage using a background thread's for all users connected.
It is based on the very useful Flask-SocketIO code from Miguel Grinberg.

https://github.com/miguelgrinberg/Flask-SocketIO

To use - please clone the repository and then set up your virtual environment using the requirements.txt file with pip and virtualenv. You can achieve this with:

```
$ git clone https://github.com/ragnar-l/NETCONF-SDN.git
$ cd python-app
$ virtualenv2 altura-gui
$ ./altura-gui/bin/pip2.7 install -r requirements.txt  #(or in Windows - sometimes python -m pip install -r requirements.txt )
```

Start the application with:

```
./altura-gui/bin/python2.7 altura.py
```

And visit http://localhost:5000 to see the GUI.
