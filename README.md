ft_irc

main program:
1. get port and password from argv
2. create socket? or something else idk bro
	- we can listen to network
	- we can send stuff to others as well
3. start the main loop

main loop:
1. listen to anything that comes from the network, and send responses as necessary
	1. when we recieve stuff, validate it to check if it is an IRC protocol command
		- if not valid, we either ignore or send something back idk bro
	2. if valid IRC command, we check if we can "excecute" the command
		- e.g. if we receive channel command, make sure the user is connected to our
			server and joined to the specific channel
		- other stuff like that depending on the command we receive
		- if we can not execute the command, send response to the client????
	3. If we can "execute" the command, we do whatever the command requires
		- e.g. set nick for the user
		- change topic etc. for the channel
		- then send response to the client probably????
	- do IRC protocol connection registration somewhere after clients connect
2. ping users to make sure they are still connected
   - if we get no response disconnect the user

classes we need:
- server
	- list of connected clients (list of user objects)
	- list of channels (list of channel objects)
	- list of server operators (list of user objects)

- channels
	- name of the channel
	- channel id (or we can use channel name as id)
	- list of users joined to the channel (list of user objects)
	- list of operators	(list of user objects)
	- topic
	- mode

- users (or clients)
	- socket
	- nick
	- username
	- list of joined channels (list of channel objects)
	- maybe list of channels where operator idk bro

- commands (what we can receive from clients)
	- each command should have a send method
		- needs target as parameter (user or channel)
		- takes the IRC protocol message parameters
	- each command should have a receive method
		- should accept IRC message parameters if there is any
		- execute whatever the message expects to be executed
	- each command should have an attribute to check if it needs operator permissions to be executed


- we need to be able to send valid IRC responses to the client
	- parser for the incoming messages
		- if we get the tag and the source, we just ignore them and get the command until the \r\n
	- assembler for the messages we send (this will most likely be called by the send method in command objects)
		- will join the command and the parameters



- MIGHT COME BACK HERE AGAIN:
	- things we need to send to client
		- ping the client to make sure they are still connected
			- if the disconnect, update channels
		- things change in a channel client is joined in
			- user joins or leaves
			- topic, mode, etc changes
			- someone sends message to channel

