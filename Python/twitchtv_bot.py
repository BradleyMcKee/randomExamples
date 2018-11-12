import socket, string

# Set all the variables necessary to connect to Twitch IRC
HOST = "irc.twitch.tv"
NICK = "creepytrash_bot"
PORT = 6667
PASS = "oauth:25qx8bxuwy0p6og2qw2jk15648bh7s"
readbuffer = ""
MODT = False

# Connecting to Twitch IRC by passing credentials and joining a certain channel
s = socket.socket()
s.connect((HOST, PORT))
s.send("PASS " + PASS + "\r\n")
s.send("NICK " + NICK + "\r\n")
s.send("JOIN #creepytrash \r\n")
# Method for sending a message
def Send_message(message):
    s.send("PRIVMSG #creepytrash :" + message + "\r\n")


while True:
    readbuffer = readbuffer + s.recv(1024)
    temp = string.split(readbuffer, "\n")
    readbuffer = temp.pop()

    for line in temp:
        # Checks whether the message is PING because its a method of Twitch to check if you're afk
        if (line[0] == "PING"):
            s.send("PONG %s\r\n" % line[1])
        else:
            # Splits the given string so we can work with it better
            parts = string.split(line, ":")

            if "QUIT" not in parts[1] and "JOIN" not in parts[1] and "PART" not in parts[1]:
                try:
                    # Sets the message variable to the actual message sent
                    message = parts[2][:len(parts[2]) - 1]
                except:
                    message = ""
                # Sets the username variable to the actual username
                usernamesplit = string.split(parts[1], "!")
                username = usernamesplit[0]

                # Only works after twitch is done announcing stuff (MODT = Message of the day)
                if MODT:
                    print username + ": " + message

                    #Plain text commands can be inserted below. When someone in the chat writes something that matches the condition the bot will automatically reply!
                    if message == "!settings":
                        Send_message(username + "You can find the settings I used below! My game sens is 3.5 horizontal, 3.5 vertical, and 3 acceleration")

                for l in parts:
                    if "End of /NAMES list" in l:
                        MODT = True
