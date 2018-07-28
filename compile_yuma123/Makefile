# Este Makefile automatiza el build de la imagen del docker y el run del container.
# La idea es que la carpeta "usrapp", que esta en el container y contiene los binarios necesarios, 
# se mapee directamente al OS nativo.

# Ejemplo de ejecucion:
# 	$ make all TARGET=nios2
# 	$ make all TARGET=arm
# 	$ make all TARGET=x86_64

all: build run

build:
	docker build --rm -f ./$(TARGET)/Dockerfile -t $(TARGET):latest ./$(TARGET)

run:
	# la carpeta destino es $(TARGET)/output ahi se copia todo lo de usrapp
	# el flag "--rm" provoca que el una vez que el container termine se borre
	docker run --rm -v $(PWD)/$(TARGET)/output:/root/output $(TARGET):latest cp -Rf /root/usrapp /root/output

clean:
	sudo rm -rf $(TARGET)/output