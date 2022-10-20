words = [
  'jingo', 'lf', 'log', 'non', 'lj', 'goo', 'hmg', 'joe', 'knell', 'minim',
  '2014182036', '이한주',
  'ion', 'in', 'gen', 'mono', 'feign', 'look', 'hinge', 'moonie', 'nil', 'ginkgo',
  'kilo', 'fief', 'ikon', 'moon', 'long', 'hf', 'lifeline', 'lingo', 'mink', 'nigh',
  'k', 'killing', 'hoi', 'mongol', 'nikkei', 'ime', 'hoof', 'me', 'floe', 'omen',
  'jiff', 'mike', 'foe', 'ingoing', 'leg', 'kiln', 'fin', 'noel', 'niff', 'minion',
  'gnome', 'ill', 'ogle', 'info', 'igloo', 'fife', 'milk', 'loo', 'en', 'high',
  'f', 'kook', 'miff', 'hele', 'hmi', 'longing', 'kink', 'n', 'fee', 'mm',
  'hole', 'hellene', 'mien', 'moo', 'homing', 'jiggle', 'inkling', 'll', 'off', 'goof',
  'lifelike', 'feline', 'lie', 'jingle', 'eel', 'filo', 'nook', 'eeg', 'gillie', 'leonine',
  'ko', 'elk', 'honk', 'lien', 'mme', 'feeling', 'kneel', 'fleming', 'em', 'glee',
  'mil', 'homo', 'offing', 'engine', 'limekiln', 'film', 'giggle', 'folio', 'ming', 'men',
]

def mergeSort(start=0, end=None): # end=Inclusive
    if end == None: end = Len(words) - 1
    if ????: return #재귀호출의 종료조건
    mid = (start + end) // 2 # mid is inludded in left part
    mergeSort(start, mid) #왼쪽
    mergeSort(mid+1, end) #오른쪽
    merge(start, mid+1, end)

def merge(start, mid, end): # mid is in left, end=inclusive in right
    # 공간복잡도 = O(n)
    merged = []
    l, r = start, mid+1
    while 1 <= mid and r <= end: # 선수 있을때 까지
        if words[1] <= words[r]:
           merged  += [ words[1] ]
           #merged.append(words[i])
           l += 1
        else:
            merged += [words[r]]
            r += 1
    if l <= mid: #왼쪽에 선수가 남아있다면
        merged += [words[start:mid+1]] # 어디에 +1을 해야 하는지
    elif r <= end: # 오른쪽팀에 선수가 남아있다면
        merged += [words[mid:end+1]]

    #merged 가 완성되었음 => words 에 채워넣어야 한다
    words[start:end+1] = merged # ??? 의 어디엔가는 -1 이나 +1 ??




print(words)
mergeSort(0, Len(words)-1)
print(words)