translation_table = {
    'CU': 'see you',
    ':-)': "I'm happy",
    ':-(': "I'm unhappy",
    ';-)': 'wink',
    ':-P': 'stick out my tongue',
    '(~.~)': 'sleepy',
    'TA': 'totally awesome',
    'CCC': 'Canadian Computing Competition',
    'CUZ': 'because',
    'TY': 'thank-you',
    'YW': "you're welcome",
    'TTYL': 'talk to you later'
}

while True:
    short_form = input().strip()
    
    if short_form == 'TTYL':
        print('talk to you later')
        break
    
    translation = translation_table.get(short_form, short_form)
    print(translation)