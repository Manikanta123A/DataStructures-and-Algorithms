import heapq

class Solution:
    def scheduleCourse(self, courses):
        courses.sort(key=lambda x: x[1])

        currDay = 0
        max_heap = []

        for course in courses:
            currDay += course[0]
            heapq.heappush(max_heap, -course[0])

            if currDay > course[1]:
                longest = -heapq.heappop(max_heap)
                currDay -= longest

        return len(max_heap)