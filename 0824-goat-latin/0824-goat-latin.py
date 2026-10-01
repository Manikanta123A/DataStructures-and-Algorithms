class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        count = 1 
        result = []
        for i in sentence.split():
            if i[0] in ['a','e','i','o','u','A','E','I','O','U']:
                i += 'ma' 
            else:
                ch = i[0] +'ma'
                i = i[1:]+ch
            i += 'a'*count
            result.append(i)
            count+=1
        return ' '.join(result)