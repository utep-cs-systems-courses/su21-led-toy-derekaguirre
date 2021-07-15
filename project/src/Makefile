# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: project.elf project-s.elf

#additional rules for files (with c file)
project.elf:  ${COMMON_OBJECTS} green_brightness-c.c buzzer.o p1_interrupt_handler.o switches.o projectMain.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

#requires the object from the assembly file
project-s.elf: ${COMMON_OBJECTS}green_brightness-s.s buzzer.o p1_interrupt_handler.o switches.o projectMain.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project.elf
	msp430loader.sh project.elf

load-s: project-s.elf
	msp430loader.sh project-s.elf

clean:
	rm -f *.o *.elf *.*~

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h

green_brightness-c.o: led.h green_brightness-c.c
