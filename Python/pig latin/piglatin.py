word = input( "Please enter a word in lower case: " )

size = len( word )

cosEnd = ""

pig = ""

i = 1

def isVowel( a ):

    if a == "a" or a == "e" or a == "i" or a == "o" or a == "u":

        #print( "%s is a vowel" %(a) )

        return True

    else:

        #print( "%s is a consonant" %(a) )

        return False

if word.isalpha() == False:

    print ("The word you enter is not valid.")

else:

    if isVowel( word[0] ):

        pig = word + "way"

    elif word[0] == "q" and word[1] == "u":

        pig = word[ 2 : size ] + "quay"

    else:

        #print( "This word begins with a cossonant." )

        cosEnd = word[0]

        while (isVowel( word[i] ) == False and i < size and word[i] != "y"):

            cosEnd = cosEnd + word[i]

            i = i + 1

        pig = word[ i : size ] + cosEnd + "ay"

    

    print( "Your Pig Latin word is %s." %(pig) )