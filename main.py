from tkinter import*
import random


class MainGUI:
    def pressed(self, row, col):
        if not self.done and self.matrix[row][col]['text'] == ' ':  # 종료가 아니고 버튼이 비어있으면
            if self.turn: #X차례
                self.matrix[row][col]['image'] = self.imageX
                self.matrix[row][col]['text'] = 'X'
            else: #O차례
                self.matrix[row][col]['image'] = self.imageO
                self.matrix[row][col]['text'] = 'O'
            self.turn = not self.turn  # 순서를 토글시킨다.
            if self.check() != ' ':
                self.done = True
                self.explain.set(self.check()+'가 이겼습니다!!!')
            elif self.turn:
                self.explain.set('플레이어 X 차례')
            else:
                self.explain.set('플레이어 O 차례')

    def check(self):  # 승패를 검사해서 승패가 결정나면 승자의 text X/O를 반환하고 결정나지 않았다면 ' '을 반환
        for i in range(3):  # 각 행과 열에 대해서 검사
            ch = self.matrix[i][0]['text']  # 각행 검사
            if ch != ' ' and ch==self.matrix[i][1]['text'] and ch==self.matrix[i][2]['text']:
                return ch
            ch = self.matrix[0][i]['text']  # 각행 검사
            if ch != ' ' and ch==self.matrix[1][i]['text'] and ch==self.matrix[2][i]['text']:
                return ch
        ch = self.matrix[0][0]['text']  # 대각선 검사 좌상->우하
        if ch != ' ' and ch==self.matrix[1][1]['text'] and ch==self.matrix[2][2]['text']:
            return ch
        ch = self.matrix[0][2]['text']  # 대각선 검사 우상->좌하
        if ch != ' ' and ch==self.matrix[1][1]['text'] and ch==self.matrix[2][0]['text']:
            return ch
        return ' '  # 승패가 결정나지 않으면 ' '을 반환

    def refresh(self):
        for i in range(3):
            for j in range(3):
                self.matrix[i][j]['image'] = self.imageE
                self.matrix[i][j]['text'] = ' '
        self.done = False
        self.turn = True

    def __init__(self):
        window = Tk()
        window.title('틱택토')
        self.done = False #종료를 나타내는 변수
        self.turn = True  #True/False 토글시키면서 2사람이 번갈아가면서 게임 수행 x/o
        frame = Frame(window)
        frame.pack()
        self.imageX = PhotoImage(file='pybook/image/x.gif')
        self.imageO = PhotoImage(file='pybook/image/o.gif')
        self.imageE = PhotoImage(file='pybook/image/empty.gif')
        self.matrix = []  #빈리스트
        for i in range(3):  # i=0,1,2
            self.matrix.append([])  # [[], [], []] 빈리스트 추가해서 2차원 리스트 만듦
            for j in range(3):  # j=0,1,2
                self.matrix[i].append(Button(frame, image=self.imageE, text=' ', \
                                             command = lambda row=i, col=j:self.pressed(row,col)))
                self.matrix[i][j].grid(row=i, column=j)
        self.explain = StringVar()
        self.explain.set('플레이어 X 차례')
        Label(window, textvariable=self.explain).pack()
        Button(window, text='다시생성', command=self.refresh).pack()

        window.mainloop()


MainGUI()
