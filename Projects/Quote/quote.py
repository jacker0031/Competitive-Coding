# Location: "C:\Users\dhruv\AppData\Roaming\Sublime Text 3\Packages\Quote"
# Keybinding: {"keys": ["ctrl+alt+s"],"command": "quote"}

import sublime_plugin, os
import random
from datetime import datetime

class QuoteCommand(sublime_plugin.TextCommand):

    def giveDate(self):
        return self.now.strftime("%d.%m.%Y") + '\n'

    def giveTime(self):
        return self.now.strftime("%H:%M:%S") + '\n'

    def problemNameExist(self, path):
        f = open(path, 'r')
        fir = f.readline()
        f.close()
        return len(fir) >= 3 and fir[:3] == '// '

    def problemName(self, path):
        if self.problemNameExist(path):
            f = open(path, 'r')
            pname = f.readline()
            f.close()
            return pname[3:]
        return '__________\n'

    def alreadyCreated(self, path):
        f = open(path, 'r')
        fir = f.readline()
        f.close()
        return len(fir) >= 2 and fir[1] == '*'


    # main code starts from here...
    def run(self, edit):
        
        self.now = datetime.now()
        path = self.view.file_name()

        if self.alreadyCreated(path):
            f = open(path, 'r')
            lines = ''
            for i in range(12):
                line = f.readline()
                if i == 3:
                    lines += '  *  Date:   ' + self.giveDate()
                    continue
                
                if i == 4:
                    lines += '  *  Time:   ' + self.giveTime()
                    continue

                lines += line

            mycode = ''
            for line in f.readlines():
                mycode += line
            f.close()
        else:
            ind = random.randrange(len(quotes))
            today_quote = quotes[ind] + '\n'
            desc = '/**\n  *  Author: dhruv_gheewala\n'
            pname = '  *  Problem: ' + self.problemName(path)
            time = '  *  Date:   ' + self.giveDate() + '  *  Time:   ' + self.giveTime()
            ending = '**/\n\n'

            lines = desc + pname + time + ending

            f = open(path, 'r')
            mycode = ''
            if self.problemNameExist(path):
                f.readline()
            for line in f.readlines():
                mycode += line
            f.close()

        f = open(path, 'w')
        f.write(lines + mycode)
        f.close()




# Quotes
quotes = [
'''/***
 ** "Program testing can be used to show the presence of bugs, but never to show their absence!"
 **     -- Edsgar W. Dijkstra
***/
''',

'''/***
 ** "Never Forget What you are,the rest of the world will not.Wear it like armour and it can never be used to hurt you"
 **     -- Tyrion Lannister
***/
''',

'''/***
 ** "Learn to forgive the ones who deserve it…and the ones who don’t."
 **
***/
''',

'''/***
 ** "Figure out how to distract yourself."
 **
***/
''',

'''/***
 ** "Be a warrior, not a worrier."
 **     -- Elizabeth archer
***/
''',

'''/***
 ** "There is only one god and his name is Death, and there is only one thing we say to Death: Not today."
 **     -- Syrio Forel
***/
''',

'''/***
 ** "Nothing f***s you harder than time."
 **     -- Ser Davos
***/
''',

'''/***
 ** "Chaos isn't a pit. Chaos is a ladder."
 **     -- Little Finger
***/
''',

'''/***
 ** "Everything before the word 'but' is horseshit."
 **     -- Jon snow
***/
''',

'''/***
 ** "A lion doesn't concern himself with the opinion of sheep."
 **     -- David Hyner
***/
''',

'''/***
 ** " Any fool can write code that a computer can understand. Good programmers write code that humans can understand "
 **     -- Martin Fowler
***/
''',

'''/***
 ** " Dream is not that which you see while sleeping it is something that does not let you sleep "
 **     -- A.P.J Abdul Kalam
***/
''',

'''/***
 ** " All that we are is the result of what we have thought. "
 **     -- Buddha
***/
''',

'''/***
 ** " Love the life you live. Live the life you love. "
 **     -- Bob Marley
***/
''',

'''/***
 ** " I have not failed. I've just found 10,000 ways that won't work. "
 **     -- Thomas Edison
***/
''',

'''/***
 ** " If you can't explain it simply, you don't understand it well enough. "
 **     -- Albert Einstein
***/
''',

'''/***
 ** " Success is most often achieved by those who don't know that failure is inevitable. "
 **     -- Coco Chanel
***/
''',

'''/***
 ** " Be yourself. Everyone else is already taken." 
 **     -- Oscar Wilde
***/
''',

'''/***
 ** " Your limitation it's only your imagination. "
 **     -- Pablo Picasso
***/
''',

'''/***
 ** " Wake up with determination. Go to bed with satisfaction. "
 **     -- George Lorimer
***/
''',

'''/***
 ** " Experience is the name everyone gives to their mistakes. "
 **     -- Oscar Wilde
***/
''',

'''/***
 ** " Knowledge is power. "
 **     -- Francis Bacon
***/
''',

'''/***
 ** " In order to be irreplaceable, one must always be different "
 **     -- Coco Chanel
***/
''',

'''/***
 ** " Simplicity is the soul of efficiency. "
 **     -- Austin Freeman
***/
''',

]