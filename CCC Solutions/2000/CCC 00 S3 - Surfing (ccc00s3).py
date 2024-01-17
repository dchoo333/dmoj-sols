import sys
N = int(input())
lines = []
urlDoc = {}
visitedURL = {}
def isSurfable(source, dest):
    visitedURL[source] = source
    if source in urlDoc and dest in urlDoc[source]:
        visitedURL.clear()
        return True
    if source in urlDoc:
        for item in urlDoc[source]:
            if item not in visitedURL:
                visitedURL[item] = item
            else:
                return False
            if isSurfable(item, dest):
                visitedURL.clear()
                return True
    return False
def parseDoc(doc):
    hrefList = []
    if "HREF" in doc:
        line = doc.split("<A HREF=\"")
        for i in range(1, len(line)):
            hrefList.append(line[i].split("\"")[0])
    return hrefList

for i in range(1, N+1):
    url = sys.stdin.readline().strip()
    while True:
        arr = []
        doc = sys.stdin.readline().strip()
        if doc == "</HTML>":
            break
        if parseDoc(doc):
            arr.extend(parseDoc(doc))
        if arr:
            for item in arr:
                if url != item:
                    lines.append(f"Link from {url} to {item}")
        teampArr = urlDoc.get(url, [])
        teampArr.extend(arr)
        urlDoc[url] = teampArr

while True:
    srcURL = sys.stdin.readline().strip()
    if srcURL == "The End":
        break
    destURL = sys.stdin.readline().strip()
    if destURL == "The End":
        break

    if isSurfable(srcURL, destURL):
        lines.append(f"Can surf from {srcURL} to {destURL}.")
    else:
        lines.append(f"Can't surf from {srcURL} to {destURL}.")

for item in lines:
    print(item)