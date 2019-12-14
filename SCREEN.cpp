#include "pch.h"
#include "SCREEN.h"

bool brickGame = false;
bool onBrickGame = false;
int dataTime = 0;


int SCREEN::getterWidth()//Hàm lấy chiều rộng của cửa sổ trò chơi, trả về Width
{
	return Width;
}
int SCREEN::getterHeight()//Hàm lấy chiều cao của cửa sổ trò chơi, trả về Height
{
	return Height;
}
int SCREEN::getterStage()//Hàm lấy thông tin giai đoạn của trò chơi, trả về stage
{
	return stage;
}
void SCREEN::PrintText(float x, float y, string text)//Hàm in ra màn hình trò chơi 1 chuỗi kí tự ở tọa độ (x,y)
{
	glRasterPos2f(x, y);//Đặt tọa độ hiển thị chuỗi
	for (int i = 0; text[i] != '\0'; i++)//Vòng lặp lấy từng kí tự trong chuỗi
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);//Hàm hiển thị từng kí tự của chuỗi
}


void SCREEN::DisplayPlayScreen(class Rectangle &b) {
	string s;
	glClearColor(0, 0.9, 0.5, 0.1);//Đặt màu nền là màu xanh lá cây
	glColor3f(0.4, 0.1, 0.0);//Đặt màu vẽ là màu nâu
	b.Update(0, 1150, TopBar + 5, TopBar);	//Cập nhật thông tin hình chữ nhật để vẽ thanh TopBar
	b.Draw();								//Vẽ thanh TopBar
	glColor3f(1.0, 0.1, 0.0);				//Đặt màu vẽ là màu đỏ
	s = to_string(LeftRacket.Score);		//Chuyển số điểm của người chơi bên trái sang kiểu string và lưu vào s
	PrintText(Width / 2 - 25, TopBar + 15, s);	//Hiển thị số điểm của người chơi bên LeftRacket
	PrintText(Width / 2, TopBar + 15, ":");		//Hiển thị dấu 2 chấm để phân cách giữa 2 số điểm
	s = to_string(RightRacket.Score);		//Chuyển số điểm của người chơi bên phải sang kiểu string và lưu vào s
	PrintText(Width / 2 + 20, TopBar + 15, s);	//Hiển thị số điểm người chơi bên RightRacket
	glColor3f(1.0, 0.1, 0.1);		//Đặt màu vẽ là màu đỏ
	ball.Draw();					//Hiển thị trái bóng ra màn hình
	glColor3f(0.0, 0.2, 0.9);		//Đặt màu vẽ là màu xanh dương
	LeftRacket.Draw();				//Vẽ 2 vợt ở 2 bên màn hình
	RightRacket.Draw();				//
}

void SCREEN::DisplayBrickGameScreen(class Rectangle &b) {
	string s;
	glClearColor(0, 0.0, 0.0, 0.0);			//Đặt màu nền là màu den
	glColor3f(1.0, 1.0, 1.0);				//Đặt màu vẽ là màu nâu
	b.Update(0, 1150, TopBar + 5, TopBar);	//Cập nhật thông tin hình chữ nhật để vẽ thanh TopBar
	b.Draw();								//Vẽ thanh TopBar
	glColor3f(1.0, 0.1, 0.0);				//Đặt màu vẽ là màu đỏ
	racketForBrickGame.Draw();				// Hien thi thanh choi cho game
	glColor3f(1.0, 1.0, 1.0);				//Đặt màu vẽ là màu trang
	ball.Draw();							//Hiển thị trái bóng ra màn hình
	DisplayLifeInBrickGame();
}

void SCREEN::DisplayWinner() {
	glColor3f(1.0, 0.1, 0.1);//Đặt màu vẽ là màu đỏ
	if (LeftRacket.Score == WinScore)//Nếu số điểm của người chơi bên trái bằng với WinScore, tức là người chơi bên trái thắng,
	{									//thì in ra chữ WINNER phía bên trái
		PrintText(200, TopBar + 15, "WINNER");
	}
	else if (RightRacket.Score == WinScore)//Tương tự như vậy với người chơi bên phải
	{
		PrintText(850, TopBar + 15, "WINNER");
	}
}

void SCREEN::DisplayScreen()//Hàm vẽ màn hình ở tất cả các giai đoạn
{
	/*
		Ở đây ta sẽ in ra nhiều hình ảnh trong thời gian ngắn để tạo ảnh động
	*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Hàm xóa màn hình trước đó
	glLoadIdentity();//Hàm thay thế ma trận hiện tại với ma trận nhận được
					// vì thư viện OpenGL sẽ lưu lại các hình ảnh dưới dạng các ma trận
	class Rectangle b;//Khai báo b là 1 hình chữ nhật, b là 1 biến thay đổi liên tục để vẽ ra các hình chữ nhật trên màn hình
	string s;//Khai báo s là 1 chuỗi string, s dùng lưu trữ chuỗi để hiển thị các chuỗi ra màn hình
	switch (stage)
	{
	case 0://Giai đoạn bắt đầu trò chơi, hiển thị màn hình Menu trò chơi
		glClearColor(0.4, 0.3, 0.9, 0.1);//Đặt màu nền màn hình là màu tím

		//Đoạn code dưới đây để vẽ chữ PING PONG
		glColor3f(0.7, 1.0, 0.1);		//Đặt màu vẽ là màu xanh lá mạ
		b.Update(180, 980, 550, 450);	//Cập nhật lại tọa độ của hình chữ nhật b
		b.Draw();						//Vẽ b ra màn hình
		glColor3f(0.4, 0.3, 0.9);		//Đặt màu vẽ là màu tím
		b.Update(200, 280, 490, 450);	//Cập nhật lại tọa độ của hình chữ nhật b
		b.Draw();						//Vẽ b ra màn hình
		b.Update(200, 240, 530, 510);	//Lặp lại thao tác tương tự như trên
		b.Draw();
		b.Update(260, 280, 550, 490);
		b.Draw();
		b.Update(300, 320, 550, 450);
		b.Draw();
		//2 Đoạn code 3 dòng trong khối glBegin glEnd dưới đây để vẽ ra 1 hình tam giác, (cụ thể tam giác này nằm ở chữ N)
		glBegin(GL_TRIANGLES);
		glVertex2f(340, 450);
		glVertex2f(340, 510);
		glVertex2f(380, 450);
		glEnd();
		//
		glBegin(GL_TRIANGLES);
		glVertex2f(380, 550);
		glVertex2f(380, 490);
		glVertex2f(340, 550);
		glEnd();
		//
		//
		b.Update(400, 420, 550, 450);
		b.Draw();
		b.Update(440, 480, 490, 470);
		b.Draw();
		b.Update(440, 460, 530, 490);
		b.Draw();
		b.Update(460, 500, 530, 510);
		b.Draw();
		b.Update(500, 600, 550, 450);
		b.Draw();
		b.Update(620, 700, 490, 450);
		b.Draw();
		b.Update(620, 660, 530, 510);
		b.Draw();
		b.Update(680, 700, 550, 490);
		b.Draw();
		b.Update(720, 760, 530, 470);
		b.Draw();
		glBegin(GL_TRIANGLES);
		glVertex2f(820, 450);
		glVertex2f(820, 510);
		glVertex2f(860, 450);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(860, 550);
		glVertex2f(860, 490);
		glVertex2f(820, 550);
		glEnd();
		b.Update(780, 800, 550, 450);
		b.Draw();
		b.Update(880, 900, 550, 450);
		b.Draw();
		b.Update(920, 960, 490, 470);
		b.Draw();
		b.Update(920, 940, 530, 490);
		b.Draw();
		b.Update(940, 980, 530, 510);
		b.Draw();
		//Kết thúc đoạn code vẽ chữ PING PONG

		//Vẽ 2 khung viền bao quanh chữ ONE PLAYER và TWO PLAYER
		glColor3f(0.7, 1.0, 0.1);
		b.Update(220, 420, 360, 300);
		b.Draw();
		b.Update(715, 915, 360, 300);
		b.Draw();
		glColor3f(0.4, 0.3, 0.9);
		b.Update(225, 415, 355, 305);
		b.Draw();
		b.Update(720, 910, 355, 305);
		b.Draw();
		//Kết thúc vẽ 2 khung viền

		//Vẽ 4 ô màu xanh lá cây bao quanh 4 phím điều khiển ở phía gần dưới của màn hình
		glColor3f(0.0, 0.3, 0.0);//Đặt màu vẽ là xanh lá cây
		b.Update(450, 480, 90, 60);
		b.Draw();
		b.Update(450, 480, 50, 20);
		b.Draw();
		b.Update(655, 685, 90, 60);
		b.Draw();
		b.Update(655, 685, 50, 20);
		b.Draw();
		//Kết thúc đoạn code vẽ 4 ô màu xanh

		//Vẽ 2 tam giác màu đỏ nằm trong 2 ô màu xanh phía dưới màn hình
		glColor3f(0.9, 0.9, 0.0);//Đặt màu vẽ là màu đỏ
		glBegin(GL_TRIANGLES);
		glVertex2f(660, 65);
		glVertex2f(680, 65);
		glVertex2f(670, 85);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(680, 45);
		glVertex2f(660, 45);
		glVertex2f(670, 25);
		glEnd();
		//Kết thúc đoạn code vẽ 2 tam giác

		//Vẽ mũi tên SelectionArrow màu đỏ 
		glColor3f(1.0, 0.2, 0.2);
		glBegin(GL_TRIANGLES);
		glVertex2f(SelectionArrow, 290);
		glVertex2f(SelectionArrow + 30, 240);
		glVertex2f(SelectionArrow - 30, 240);
		glEnd();
		//Kết thúc đoạn code vẽ mũi tên SelectionArrow

		//Hiển thị ra các chuỗi kí tự trên màn hình ở tọa độ tương ứng
		glColor3f(1.0, 1.0, 0.0);//Đặt màu vẽ là màu vàng
		PrintText(228, Height / 2-5, "PONG 1 PLAYER");
		PrintText(720, Height / 2-5, "BRICK BREAKER");
		PrintText(480, 140, "CONTROL KEYS");
		PrintText(540, 65, "Go Up");
		PrintText(530, 25, "Go Down");
		PrintText(455, 70, "W");
		PrintText(458, 30, "S");
		//
		break;
	case 1:case 5://2 Giai đoạn này là chế độ 1 và 2 người chơi thì các đối tượng cần hiển thị ra màn hình giống nhau hoàn toàn
		DisplayPlayScreen(b);
		break;
	case 3://Giai đoạn đã chơi xong và đã xác định được người thắng
		DisplayPlayScreen(b);
		//Kết thúc đoạn code giống với case 1 và case 2

		//Hiển thị ra chữ WINNER bên phía người thắng
		DisplayWinner();
		//

		//Ta thực hiện các thao tác tương tự ở phần case 0 để in ra 2 ô PLAY AGAIN và QUIT GAME
		glColor3f(0.7, 1.0, 0.1);
		b.Update(220, 420, 560, 500);
		b.Draw();
		b.Update(715, 915, 560, 500);
		b.Draw();
		glColor3f(0, 0.9, 0.5);
		b.Update(225, 415, 555, 505);
		b.Draw();
		b.Update(720, 910, 555, 505);
		b.Draw();
		glColor3f(0.4, 0.3, 0.9);//Đặt màu vẽ là màu tím
		PrintText(450, TopBar - 30, "Do you want to play again?");
		PrintText(255, 523, "PLAY AGAIN");
		PrintText(755, 523, "QUIT GAME");
		//

		//Tương tự như đoạn code ở trong phần case 0 để hiển thị mũi tên chọn chế độ SelectionArrow
		glColor3f(1.0, 0.2, 0.2);
		glBegin(GL_TRIANGLES);
		glVertex2f(SelectionArrow, 490);
		glVertex2f(SelectionArrow + 30, 440);
		glVertex2f(SelectionArrow - 30, 440);
		glEnd();
		break;
	case 4://Sau khi chơi xong và người chơi chọn QUIT GAME
		glColor3f(0.0, 0.2, 0.9);//Đặt màu vẽ là màu tím
		//Hiển thị ra màn hình 2 dòng kí tự như bên dưới
		PrintText(Width / 2 - 80, Height / 2 + 30, "Thank you for playing!");
		PrintText(Width / 2 - 100, Height / 2 - 30, "Press ESC to close window");
		break;
	case 2:
		if (!brickGame) {
			brick.InitRandomMatch();
			brickGame = true;
		}
		if (!onBrickGame) {
			onBrickGame = !onBrickGame;
			SetBallValueForBrickGame();
		}
		brick.Draw();
		DisplayBrickGameScreen(b);
		dataTime++;
		if (dataTime == 1500) {
			dataTime = 0;
			brick.spawnItem();
		}
		brick.reduceItemTime();
		for (int i = 0; i < item.size(); i++) {
			item[i].fall();
		}
		
		break;
	case 6:
		DisplayLostScreen();
		break;
	}
	//
	glutSwapBuffers();	//Thực hiện thao tác hoán đổi 2 buffers
	glutPostRedisplay();//Lặp lại thao vẽ trên cửa sổ đang mở
}

/*
	Hàm hiển thị số mạng chơi trong game
*/
void SCREEN::DisplayLifeInBrickGame() {
	glColor3f(1.0, 0.5, 0.5);
	PrintText(Width/2-100, TopBar + 10, "YOUR LIVES: ");
	string s = to_string(racketForBrickGame.Score);
	PrintText(Width/2+50, TopBar + 10, s);
	glColor3f(1.0, 1.0, 1.0);
}

void SCREEN::ResizeScreen()//Hàm thay đổi lại các thông tin của màn hình sau mỗi lần hiển thị
{
	glViewport(0, 0, Width, Height);				//Thay đổi kích thước Viewport
	glMatrixMode(GL_PROJECTION);					//Xét thao tác chiếu ta gọi 2 hàm như bên cạnh
	glLoadIdentity();								//
	glOrtho(0.0, Width, 0.0, Height, 0.0, 1.0);	//Thực hiện phép chiếu trực giao (glOrtho là chiếu trực giao, còn 1 thao tác chiếu nữa là chiếu phối cảnh nhưng ta không sử dụng)
	glMatrixMode(GL_MODELVIEW);						//Xét thao tác trên ModeView ta gọi 2 hàm như bên cạnh
	glLoadIdentity();								//
}
void SCREEN::UpdateBall()//Hàm cập nhật thông tin của quả bóng (tọa độ bóng, xử lí va chạm) và số điểm người chơi sau mỗi lượt chạm bóng
{
	if (ball.y + ball.r > TopBar || ball.y - ball.r < 0)//Nếu y+r (viền ngoài phía trên của quả bóng) > TopBar, tức là chạm phần biên trên
														//hoặc y-r (viền ngoài phía dưới của quả bóng) < 0, tức là chạm biên dưới
		ball.yDirection *= -1;					//Thì quả bóng đảo ngược hướng di chuyển
	
	if (ball.x + ball.r > Width)		//Nếu x+r (viền ngoài phía bên trái của quả bóng) > Width, tức là chạm biên phải
	{											//Thì:
		ball.x = Width / 2;						//Đặt lại hoành độ của quả bóng ở giữa sân
		ball.y = TopBar / 2;					//Đặt lại tung độ của quả bóng ở giữa sân
		ball.xDirection *= -1;					//Quả bóng sẽ bắt đầu di chuyển về phía ngược lại
		ball.yDirection = 0;					//yDirection=0 tức là quả bóng sẽ di chuyển theo phương nằm ngang
		ball.CurrentSpeed = ball.FirstSpeed;	//Đặt lại tốc độ hiện tại của bóng = tốc độ ban đầu khởi tạo
		LeftRacket.Score++;						//Tính điểm cho người chơi đối diện, tức là người phía bên trái
	}

	if (ball.x - ball.r < 0)			//Tương tự như phía trên với x-r (viền ngoài bên phải của quả bóng) < 0, tức là chạm biên trái
	{											//Thì: các thông số được thiết lập giống như trên
		ball.x = Width / 2;						//
		ball.y = TopBar / 2;					//
		ball.xDirection *= -1;					//
		ball.yDirection = 0;					//
		ball.CurrentSpeed = ball.FirstSpeed;	//
		RightRacket.Score++;					//Chỉ có tính điểm là ngược lại, tức là người phía bên phải
	}
	//Trường hợp chạm vợt trái
	if (ball.y > LeftRacket.Bottom && ball.y < LeftRacket.Top && ball.x + ball.xDirection*ball.CurrentSpeed - ball.r < LeftRacket.Right && ball.x - ball.r>LeftRacket.Left)
	{	//Nếu y > bottom và y < top, tức là quả bóng nằm giữa 2 đầu của vợt (vợt hứng được)
		//Và x-r > Left, tức là quả bóng chưa bị trôi ra sau vợt
		//Và đồng thời x-r + xDirection*CurrentSpeed (đây là điểm đến tiếp theo của quả bóng) < Right,
		//tức là ngay sau đó bước di chuyển tiếp theo quả bóng sẽ chạm vợt
		//Thì:
		float length = LeftRacket.Top - LeftRacket.Bottom;//Ta tính chiều dài của vợt = Top-Bottom
		float k = fabs(ball.y - (LeftRacket.Top + LeftRacket.Bottom) / 2) / length; //k là tỉ lệ của KHOẢNG CÁCH (nơi mà bóng chạm vợt đến tâm vợt) so với CHIỀU DÀI VỢT
		//Dựa vào tỉ lệ này ta xác định góc nảy của bóng, nếu bóng càng chạm vào phía ngoài của vợt thì góc nảy càng lớn, và ngược lại nếu càng chạm gần tâm thì góc nảy càng nhỏ								
		ball.xDirection *= -1;		//Sau khi chạm vợt thì bóng sẽ văng ngược lại, cho nên xDirection *=-1
		if (LeftRacket.Status == 1)	//Nếu status của vợt bằng 1, tức là vợt đang di chuyển lên,
			ball.yDirection = k;	//Thì: thì quả bóng sẽ đi lên, tức yDirection = k > 0
		else//Ngược lại, tức là vợt đang đi xuống
			ball.yDirection = -k;	//Thì quả bóng sẽ đi xuống, yDirection = -k < 0
		
		ball.CurrentSpeed += ball.CurrentSpeed*ball.IncreaseSpeed;//Cập nhật lại tốc độ của quả bóng, sau va chạm thì tốc độ sẽ tăng theo tỉ lệ của IncreaseSpeed (IncreaseSpeed mặc định là 0.1)
		LeftRacket.Speed += LeftRacket.Speed*ball.IncreaseSpeed / 2;//Cập nhật lại tốc độ di chuyển của vợt, điều này có ý nghĩa khi quả bóng di chuyển nhanh lên thì vợt cũng có thể như vậy
																	//Tuy nhiên độ tăng tốc độ của vợt sẽ chỉ bằng 1 nửa so với bóng
		ball.x = LeftRacket.Right + ball.r;	//Lúc này đang trong điều kiện if phía trên, tức là chạm vợt trái 
		//Nên tọa độ của quả bóng lúc sau va chạm sẽ được đặt ngay sát phía bên phải của vợt trái
	}
	//Trường hợp quả bóng chạm vợt bên phải cũng tương tự như trên, ta chỉ cần xét ngược lại về phía bên phải
	else if (ball.y > RightRacket.Bottom && ball.y < RightRacket.Top && ball.x + ball.xDirection*ball.CurrentSpeed + ball.r > RightRacket.Left && ball.x + ball.r < RightRacket.Right)
	{
		float length = RightRacket.Top - RightRacket.Bottom;
		float k = fabs(ball.y - (RightRacket.Top + RightRacket.Bottom) / 2) / length;
		ball.xDirection *= -1;
		if (RightRacket.Status == 1)
			ball.yDirection = k;
		else
			ball.yDirection = -k;
		ball.CurrentSpeed += ball.CurrentSpeed*ball.IncreaseSpeed;
		RightRacket.Speed += RightRacket.Speed*ball.IncreaseSpeed / 2;
		ball.x = RightRacket.Left - ball.r;
	}
	else//Nếu không nằm trong các trường hợp trên, tức là quả bóng đang di chuyển trong sân và không chạm vào bất cứ thứ gì
	{
		ball.x += ball.xDirection*ball.CurrentSpeed;//Thì hoàng độ x của quả bóng sẽ là hướng di chuyển nhân với tốc độ của nó
	}
	ball.y += ball.yDirection*ball.CurrentSpeed;//Tương tự với hoành độ, tung độ của quả bóng cũng như vậy
}

void SCREEN::UpdateRacketItem(int color) {
	int w = racketForBrickGame.getRight() - racketForBrickGame.getLeft();
	switch (color) {
	case 1:
		// làm thanh ngắn lại
		racketForBrickGame.setLeft(racketForBrickGame.getLeft() + w * extraWidth); 
		racketForBrickGame.setRight(racketForBrickGame.getRight() - w * extraWidth);
		break;
	case 2:
		// làm thanh dài ra
		racketForBrickGame.setLeft(racketForBrickGame.getLeft() - w * extraWidth);
		racketForBrickGame.setRight(racketForBrickGame.getRight() + w * extraWidth);
		break;
	case 3:
		// tăng mạng (dùng score để không phải tạo thêm biến)
		racketForBrickGame.Score++;
		break;
	}
}

void SCREEN::UpdateItem(ITEM new_item) {
	if (new_item.getStatus() != 0) {
		item.push_back(new_item);
	}
	for (int i = 0; i < item.size(); i++) {
		if (item[i].isRacketCollide(racketForBrickGame)) {
			UpdateRacketItem(item[i].getStatus());
			item[i].deleteItem();
			item.erase(item.begin() + i);
		}
	}
}

void SCREEN::UpdateBallForBrickGame() {
	// TH không hứng được banh
	if (ball.y <= 0) {
		// nếu ng chơi ăn được cục tăng mạng
		if (racketForBrickGame.Score > 0) {
			racketForBrickGame.Score--;
			SetBallValueForBrickGame();
		}
		// hết mạng
		else if (racketForBrickGame.Score == 0) {
			stage = 6;
		}
		return;
	}
	// TH ra chạm 2 biên trái phải
	if (ball.x + ball.r >= Width || ball.x - ball.r <= 0) {
		ball.xDirection *= -1;
	} 
	// chạm biên trên
	if (ball.y + ball.r > TopBar) {
		ball.yDirection *= -1;
	} 
	// TH chạm thanh chơi
	//ball.x - ball.r > racketForBrickGame.Left && ball.x + ball.r < racketForBrickGame.Right && ball.y - ball.yDirection*ball.CurrentSpeed <= racketForBrickGame.Top
	else if (racketForBrickGame.intersects(ball)) {
		float k = fabs(ball.x - (racketForBrickGame.Left + racketForBrickGame.Right) / 2) / (racketForBrickGame.Right - racketForBrickGame.Left);
		if (racketForBrickGame.Status == 2) {
			ball.setXDir(k);
		}
		else {
			ball.setXDir(-k);
		}
		ball.CurrentSpeed += ball.CurrentSpeed*ball.IncreaseSpeed;
		racketForBrickGame.Speed += racketForBrickGame.Speed * ball.IncreaseSpeed / 2;
	}
	else {
		// hàm nhận vào vị trí tiếp theo của banh và xét nó với từng viên gạch và trả ra viên gạch bị chạm (nếu có) 
		ITEM newItem = brick.isCollide(ball);
		UpdateItem(newItem);
	}
	ball.x += ball.xDirection*ball.CurrentSpeed;
	ball.y += ball.yDirection*ball.CurrentSpeed;
}

void SCREEN::SetBallValueForBrickGame()
{
	ball.x = Width / 2;
	ball.y = racketForBrickGame.Top + 50;
	ball.yDirection = 1;
	ball.xDirection = (float)(rand() % 9 + 1) / 10;
}
void SCREEN::UpdateLeftRacket()//Hàm cập nhật thông tin của vợt bên trái (vợt di chuyển lên hay xuống)
{
	//Hàm GetAsyncKeyState(VK) sẽ trả về true nếu ta nhấn phím VK, nếu không thì trả về false (với VK là mã phím đã được định nghĩa trước)
	if (GetAsyncKeyState(VK_W) && LeftRacket.Top < TopBar)//Nếu ta nhấn phím W và vợt vẫn chưa chạm biên trên
	{
		LeftRacket.Top += LeftRacket.Speed;		//Thì Top và Bottom của vợt sẽ được cộng thêm, tức là di chuyển lên
		LeftRacket.Bottom += LeftRacket.Speed;	//
		LeftRacket.Status = 1;					//Status của vợt được cập nhật là = 1, tương ứng với đi lên
	}
	else if (GetAsyncKeyState(VK_S) && LeftRacket.Bottom > 0)//Ngược lại nếu ta nhấn phím S và vợt vẫn chưa chạm biên dưới
	{
		LeftRacket.Top -= LeftRacket.Speed;		//Thì Top và Bottom của vợt sẽ bị trừ đi, tức là di chuyển xuống
		LeftRacket.Bottom -= LeftRacket.Speed;	//
		LeftRacket.Status = -1;					//Status của vợt được cập nhật là = -1, tương ứng với đi xuống
	}
}
void SCREEN::UpdateRightRacket()//Hàm cập nhật thông tin vợt phải
{//Hoàn toàn tương tự như vợt trái, chỉ khác ở chỗ phím di chuyển là mũi tên lên và mũi tên xuống
	if (GetAsyncKeyState(VK_UP) && RightRacket.Top < TopBar)
	{
		RightRacket.Top += RightRacket.Speed;
		RightRacket.Bottom += RightRacket.Speed;
		RightRacket.Status = 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) && RightRacket.Bottom > 0)
	{
		RightRacket.Top -= RightRacket.Speed;
		RightRacket.Bottom -= RightRacket.Speed;
		RightRacket.Status = -1;
	}
}

void SCREEN::UpdateBrickGameRacket() {
	if (GetAsyncKeyState(VK_RIGHT) && racketForBrickGame.Right < Width) {
		racketForBrickGame.Right += racketForBrickGame.Speed;
		racketForBrickGame.Left += racketForBrickGame.Speed;
		racketForBrickGame.Status = 2;

	}
	else if (GetAsyncKeyState(VK_LEFT) && racketForBrickGame.Left > 0) {
		racketForBrickGame.Right -= racketForBrickGame.Speed;
		racketForBrickGame.Left -= racketForBrickGame.Speed;
		racketForBrickGame.Status = -2;
	}
}

void SCREEN::UpdateAutoRacket()//Hàm cập nhật vợt di chuyển tự động đón bóng
{
	if (LeftRacket.Top < ball.y + ball.r && LeftRacket.Top < TopBar && ball.x < Width / 3 * 2)
		//Nếu Top < y+r, tức là vợt còn nằm phía dưới quả bóng
		//Và  Top < TopBar, tức là vợt chưa chạm biên trên
		//Và x < Width/3*2, tức là quả bóng chưa di chuyển qua 2/3 sân (ở đây có điều kiện này để xem như vợt 'phản ứng' chậm hơn một chút)
	{//Thì:
		LeftRacket.Top += LeftRacket.Speed;		//Di chuyển vợt lên trên
		LeftRacket.Bottom += LeftRacket.Speed;	//
		LeftRacket.Status = 1;					//Cập nhật Status là 1, ứng với đi lên
	}
	//Tương tự nếu Bottom > y-r, tức là vợt nằm phía trên quả bóng, thì ta cho vợt di chuyển xuống
	if (LeftRacket.Bottom > ball.y - ball.r && LeftRacket.Bottom > 0 && ball.x < Width / 3 * 2)
	{
		LeftRacket.Top -= LeftRacket.Speed;
		LeftRacket.Bottom -= LeftRacket.Speed;
		LeftRacket.Status = -1;
	}
	//Ta vẫn có thể thắng được vợt di chuyển tự động, bởi vì tốc độ khi tăng lên của vợt là chậm hơn so với tốc độ của bóng
	//Nếu tốc độ bóng đủ nhanh, góc nảy của bóng đủ lớn, thì vợt sẽ không di chuyển để đón kịp
}

void SCREEN::UpdateScreen()//Hàm cập nhật toàn bộ thông tin của các đối tượng trên màn hình
{
	switch (stage)
	{
	case 0://Giai đoạn bắt đầu trò chơi, tức là đang hiển thị màn hình Menu
		if (GetAsyncKeyState(VK_LEFT))//Nếu ta nhấn phím mũi tên trái, tức là chọn ô "ONE PLAYER"
		{
			SelectionArrow = 320;//Thì mũi tên sẽ chỉ về ô bên trái (320 là hoành độ của ô phía bên trái)
		}
		else if (GetAsyncKeyState(VK_RIGHT))//Ngược lại nếu ta nhấn phím mũi tên phải, tức là chọn ô "TWO PLAYER"
		{
			SelectionArrow = 815;//Thì mũi tên sẽ chỉ về ô bên phải (815 là hoành độ của ô phía bên phải)
		}
		else if (GetAsyncKeyState(VK_ENTER))//Nếu ta nhấn phím ENTER, tức là xác nhận việc chọn
		{
			if (SelectionArrow == 320)//Nếu mũi tên đang ở bên trái thì gán stage = 1, tức là vào chế độ 1 người chơi
				stage = 1;
			if (SelectionArrow == 815)//Nếu mũi tên đang ở bên phải thì gán stage = 2, tức là vào chế độ 2 người chơi
				stage = 2;
		}
		break;
	case 1://Trường hợp 1 người chơi
		if (LeftRacket.Score == WinScore || RightRacket.Score == WinScore)//Nếu có 1 người chơi đạt đủ điểm WinScore thì chuyển sang giai đoạn 3
			stage = 3;
		UpdateBall();			//Cập nhật thông tin quả bóng
		UpdateAutoRacket();		//Cập nhật thông tin của vợt tự động (vợt trái)
		UpdateRightRacket();	//Cập nhật thông tin vợt phải (vợt người chơi)
		break;
	case 2:
		/*if (LeftRacket.Score == WinScore || RightRacket.Score == WinScore)//Nếu có 1 nươời chơi đạt đủ điểm để thắng thì chuyển sang giai đoạn 3
			stage = 3;
		UpdateBall();			//Cập nhật thông tin quả bóng
		UpdateLeftRacket();		//Cập nhật thông tin vợt của người chơi bên trái
		UpdateRightRacket();	//Cập nhật thông tin vợt của người chơi bên phải
		break;*/
		UpdateBallForBrickGame();
		UpdateBrickGameRacket();
		break;
	case 3://Giai đoạn sau khi chơi xong và đã xác định được người thắng
		//Ta thiết lập các thông số của 3 đối tượng: bóng, vợt trái, vợt phải lại giống ban đầu, và không di chuyển chúng nữa

		ball.x = Width / 2;		//Các thông số của bóng
		ball.y = TopBar / 2;	//
		ball.r = 5;			//
		ball.FirstSpeed = 0;	//
		ball.CurrentSpeed = 0;	//
		//
		LeftRacket.Left = 50;	//Các thông số của vợt trái
		LeftRacket.Right = 80;	//
		LeftRacket.Top = 400;	//
		LeftRacket.Bottom = 250;//
		LeftRacket.Speed = 0;	//
		//
		RightRacket.Left = 1070;	//Các thông số của vợt phải
		RightRacket.Right = 1100;	//
		RightRacket.Top = 400;		//
		RightRacket.Bottom = 250;	//
		RightRacket.Speed = 0;		//
		//
		//Lúc này ta cũng in ra 2 ô lựa chọn là "PLAY AGAIN" và "QUIT GAME"
		if (GetAsyncKeyState(VK_LEFT))//Nếu chọn ô bên trái
		{
			SelectionArrow = 320;//Di chuyển tọa độ mũi tên sang trái
		}
		else if (GetAsyncKeyState(VK_RIGHT))//Nếu chọn ô bên phải
		{
			SelectionArrow = 815;//Di chuyển mũi tên sang phải
		}
		else if (GetAsyncKeyState(VK_ENTER))//Nếu nhấn ENTER, tức là xác nhận đã chọn xong
		{
			Sleep(100);//Tạm ngưng việc tương tác với bàn phím trong 100 miliseconds
						//Nếu ta không có hàm tạm ngưng này thì khi ta ấn ENTER, sẽ bị đè phím và chương trình tự động vào lại chế độ 1 người chơi nếu ta chọn PLAY AGAIN
			if (SelectionArrow == 320)//Nếu mũi tên ở bên trái, tức là chọn PLAY AGAIN 
			{
				SetUpDefaultStartValue();//thì ta đặt lại các thông số như ban đầu và vào stage=0, hiển thị Menu chọn và chơi lại
				
			}
			else if (SelectionArrow == 815)//Nếu mũi tên ở bên phải, tức là chọn QUIT GAME, thì gán stage =4 và thoát game
				stage = 4;
		}
		break;
	case 6:
		//Lúc này ta cũng in ra 2 ô lựa chọn là "PLAY AGAIN" và "QUIT GAME"
		if (GetAsyncKeyState(VK_LEFT))//Nếu chọn ô bên trái
		{
			SelectionArrow = 320;//Di chuyển tọa độ mũi tên sang trái
		}
		else if (GetAsyncKeyState(VK_RIGHT))//Nếu chọn ô bên phải
		{
			SelectionArrow = 815;//Di chuyển mũi tên sang phải
		}
		else if (GetAsyncKeyState(VK_ENTER))//Nếu nhấn ENTER, tức là xác nhận đã chọn xong
		{
			Sleep(100);//Tạm ngưng việc tương tác với bàn phím trong 100 miliseconds
						//Nếu ta không có hàm tạm ngưng này thì khi ta ấn ENTER, sẽ bị đè phím và chương trình tự động vào lại chế độ 1 người chơi nếu ta chọn PLAY AGAIN
			if (SelectionArrow == 320)//Nếu mũi tên ở bên trái, tức là chọn PLAY AGAIN 
			{
				SetUpDefaultStartValue();//thì ta đặt lại các thông số như ban đầu và vào stage=0, hiển thị Menu chọn và chơi lại
				onBrickGame = false;
				brickGame = false;
			}
			else if (SelectionArrow == 815)//Nếu mũi tên ở bên phải, tức là chọn QUIT GAME, thì gán stage =4 và thoát game
				stage = 4;
		}
		break;
	}
}

void SCREEN::DisplayLostScreen() {
	class Rectangle b;
	//Ta thực hiện các thao tác tương tự ở phần case 0 để in ra 2 ô PLAY AGAIN và QUIT GAME
	glColor3f(1.0, 0.0, 1.0);
	b.Update(220, 420, TopBar - 250, TopBar - 300);
	b.Draw();
	b.Update(715, 915, TopBar - 250, TopBar - 300);
	b.Draw();
	glColor3f(1.0, 0.5, 0.5);
	b.Update(225, 415, TopBar - 245, TopBar - 305);
	b.Draw();
	b.Update(720, 910, TopBar - 245, TopBar - 305);
	b.Draw();
	glColor3f(0.4, 0.3, 0.9);//Đặt màu vẽ là màu tím
	PrintText(500, TopBar - 200, "YOU LOST!!!");
	PrintText(250, TopBar - 280, "PLAY AGAIN");
	PrintText(750, TopBar - 280, "QUIT GAME");
	//

	//Tương tự như đoạn code ở trong phần case 0 để hiển thị mũi tên chọn chế độ SelectionArrow
	glColor3f(1.0, 0.2, 0.2);
	glBegin(GL_TRIANGLES);
	glVertex2f(SelectionArrow, TopBar - 310);
	glVertex2f(SelectionArrow + 30, TopBar - 350);
	glVertex2f(SelectionArrow - 30, TopBar - 350);
	glEnd();
}
void SCREEN::SetUpDefaultStartValue()//Hàm khởi tạo các giá trị ban đầu
{
	Width = 1150;
	Height = 650;
	TopBar = 600;
	stage = 0;
	SelectionArrow = 320;
	WinScore = 5;
	//
	ball.x = Width / 2;
	ball.y = TopBar / 2;
	ball.r = 5;
	ball.FirstSpeed = 0.2;
	ball.CurrentSpeed = 0.4;
	ball.IncreaseSpeed = 0.1;//Thông số tốc độ gia tăng của bóng sau mỗi lần chạm vợt là 0.1 tức là 10% theo như đề
							//Các thông số còn lại là mặc định do người lập trình tự điều chỉnh để phù hợp với kích thước giao diện
	ball.xDirection = 1;
	ball.yDirection = 0;
	//
	LeftRacket.setValue(50, 80, 400, 250, 0.5, 1, 0);
	//
	RightRacket.setValue(1070, 1100, 400, 250, 0.5, 1, 0);
	//
	racketForBrickGame.setValue(Width / 2 - 75, Width / 2 + 75, 55, 45, 0.5, 2, 0);
	//
	brick.Init();
}
SCREEN::SCREEN()
{
}


SCREEN::~SCREEN()
{
}
