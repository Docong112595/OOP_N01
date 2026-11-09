# OOP_N01

# Bai thuc hanh 01

BÀI TẬP THỰC HÀNH OOP

HỆ THỐNG QUẢN LÝ BÃI ĐỖ XE – GIAI ĐOẠN 1

Giảng viên: Nguyễn Hạnh Phúc - FIT - VMU
Ngôn ngữ lập trình: C++ (Chuẩn C++11 trở lên)

Đề bài chung cho tất cả các giai đoạn

Sinh viên sẽ thiết kế và xây dựng một hệ thống quản lý bãi đỗ xe bằng C++ theo nguyên lý OOP. Hệ thống cho phép:
• Tạo và quản lý nhiều bãi đỗ xe (parking lots) với các kích thước khác nhau.
• Tạo và quản lý nhiều phương tiện (vehicles) như ô tô, xe máy, xe đạp.
• Thực hiện các thao tác: thêm, xóa, tìm kiếm, hiển thị thông tin.
• Tính toán phí đỗ xe theo quy tắc nghiệp vụ.
• Thống kê và báo cáo dữ liệu.
Yêu cầu cốt lõi: Xây dựng các lớp đối tượng (ParkingLot, Vehicle, SystemInterface) và xử lý các thao tác thêm, xóa, hiển thị thông tin một cách có tổ chức, đúng đắn về mặt thiết kế OOP.

1. MỤC TIÊU & YÊU CẦU KỸ THUẬT

• Chủ đề: Đóng gói (Encapsulation), Thiết kế Lớp (Class), Biến đơn và Luồng điều khiển cơ bản.
• Mục tiêu: Thiết kế ứng dụng console hướng đối tượng quản lý bãi đỗ xe cho một công ty.
• Hạn chế bắt buộc (Strict Constraints):
	1. TÍNH ĐÓNG GÓI: Tất cả các thuộc tính (instance variables) của lớp phải ở phạm vi private. Tương tác dữ liệu bắt buộc thông qua các phương thức public (Getters, Setters, Constructors).
	2. KHÔNG SỬ DỤNG MẢNG VÀ CON TRỎ: Tuyệt đối KHÔNG sử dụng Mảng tĩnh (C-style array), Mảng C++ (std::array), Mảng động/Vector (std::vector), hay Con trỏ (pointers / new / delete).
	3. LƯU TRỮ: Quản lý số lượng đối tượng cố định thông qua các biến đối tượng đơn lẻ và biến cờ trạng thái (boolean flags).

2. CẤU TRÚC VÀ THIẾT KẾ CÁC LỚP (CLASS SPECIFICATIONS)

Chương trình gồm 3 lớp chính:

2.1 Lớp 1: Vehicle (Đại diện cho một phương tiện đỗ)

• Thuộc tính (private):
	• int vehicleID: Mã định danh duy nhất của xe.
	• std::string vehicleType: Loại xe (Chỉ nhận 3 giá trị: "Car", "Motorcycle", "Bicycle", không phân biệt chữ hoa/thường).
	• int entryTime: Giờ vào bãi (Số nguyên từ 0 đến 23, trong đó 0 = 12am, 23 = 11pm).
	• int parkingDuration: Số giờ đỗ dự kiến (Số nguyên từ 1 đến 23, đảm bảo trong cùng một ngày).
	• double parkingFee: Phí đỗ xe được tính toán (đơn vị: VND).
	• bool isOccupied: Cờ xác định vị trí xe này có đang chứa dữ liệu thực hay không (mặc định false).
• Phương thức (public):
	• Constructor mặc định và Constructor có tham số đầy đủ.
	• Các hàm Getters / Setters cho tất cả thuộc tính.
	• void calculateFee(): Hàm tính phí đỗ xe tự động theo quy tắc ở Mục 3.
	• void display(): In thông tin chi tiết của xe ra màn hình.

2.2 Lớp 2: ParkingLot (Đại diện cho một bãi đỗ xe)

• Thuộc tính (private):
	• int parkID: Mã định danh bãi đỗ xe.
	• char size: Kích thước bãi đỗ ('S' - Nhỏ, 'M' - Trung bình, 'L' - Lớn):
		• S (Small): Chứa tối đa 1 xe (vehicle1).
		• M (Medium): Chứa tối đa 2 xe (vehicle1, vehicle2).
		• L (Large): Chứa tối đa 3 xe (vehicle1, vehicle2, vehicle3).
	• Vehicle vehicle1, Vehicle vehicle2, Vehicle vehicle3: Các biến đối tượng xe đơn lẻ.
	• bool hasVehicle1, bool hasVehicle2, bool hasVehicle3: Cờ kiểm tra trạng thái ô trống.
• Phương thức (public):
	• Constructor mặc định và Constructor khởi tạo bãi đỗ theo parkID và size.
	• bool addVehicle(const Vehicle& v): Thêm xe vào ô trống phù hợp theo sức chứa của size.
	• bool removeVehicle(int vID): Xóa xe khỏi bãi theo mã vehicleID.
	• void displayLotInfo(): Hiển thị ID bãi, kích thước và danh sách các xe hiện có.

2.3 Lớp 3: SystemInterface (Giao diện và điều hành hệ thống)

• Thuộc tính (private):
	• ParkingLot parkingLot1, ParkingLot parkingLot2, ParkingLot parkingLot3: Quản lý tối đa 3 bãi đỗ xe đơn lẻ.
	• bool hasLot1, bool hasLot2, bool hasLot3: Cờ theo dõi bãi đỗ tồn tại.
• Phương thức (public):
	• Lớp duy nhất chứa hàm main() và xử lý nhập/xuất Console (std::cin, std::cout).
	• void runMenu(): Hiển thị menu và điều phối các chức năng chương trình.

3. QUY TẮC TÍNH PHÍ ĐỖ XE (PARKING FEE RULES)

Phí đỗ xe dựa trên Loại xe, Thời gian vào bãi (entryTime) và Thời lượng đỗ (parkingDuration):
1. Biểu phí cơ bản theo giờ:
	• Ô tô (Car): $6.00 / giờ.
	• Xe máy (Motorcycle): $4.00 / giờ.
	• Xe đạp (Bicycle): $2.00 / giờ.
2. Khung giờ cao điểm (Peak Hours):
	• Sáng: từ 6:00 đến trước 10:00 (khung giờ 6, 7, 8, 9).
	• Chiều/Tối: từ 15:00 đến trước 19:00 (khung giờ 15, 16, 17, 18).
3. Công thức tính phí:
	• Trong 2 giờ đầu tiên:
		• Nếu vào Giờ cao điểm: Áp dụng mức tăng 30% (+30%) so với đơn giá chuẩn.
		• Nếu vào Giờ thấp điểm: Áp dụng mức giảm 5% (-5%) so với đơn giá chuẩn.
	• Từ giờ thứ 3 trở đi (áp dụng cho các giờ từ giờ thứ 3):
		• Giảm giá 10% (-10%) cho đơn giá theo giờ, bất kể vào giờ cao điểm hay thấp điểm.

4. YÊU CẦU CHỨC NĂNG MENU (MAIN MENU REQUIREMENTS)

Chương trình hiển thị menu lặp lại liên tục cho đến khi người dùng chọn thoát:
1. Tạo Bãi đỗ xe mới: Nhập parkID và size ('S', 'M', 'L'). Tối đa 3 bãi. Kiểm tra trùng lặp ID hoặc vượt quá sức chứa.
2. Thêm xe vào bãi đỗ: Nhập thông tin xe (vehicleID, vehicleType, entryTime, parkingDuration). Tự động xếp vào bãi đỗ còn chỗ thích hợp dựa trên size. Tự động tính parkingFee.
3. Xóa một Bãi đỗ xe: Nhập parkID để xóa bãi đỗ ra khỏi hệ thống.
4. Lấy xe ra khỏi bãi đỗ: Nhập vehicleID để lấy xe ra khỏi bãi.
5. Hiển thị danh sách tất cả các Bãi đỗ xe: Liệt kê thông tin tổng quan của các bãi đỗ hiện có (ID, kích thước, số lượng xe).
6. Hiển thị danh sách xe theo bãi cụ thể: Nhập parkID, in ra thông tin chi tiết từng xe trong bãi đó.
7. Liệt kê xe theo loại phương tiện: Nhập loại xe (Car/Motorcycle/Bicycle), in danh sách các xe khớp loại và bãi đỗ tương ứng.
8. Xem báo cáo tóm tắt phí đỗ xe trung bình: Tính và hiển thị phí đỗ xe trung bình cho từng loại xe trên toàn hệ thống và phân tích chi tiết theo từng bãi đỗ.
9. Thoát chương trình


BÀI TẬP THỰC HÀNH OOP 
 HỆ THỐNG QUẢN LÝ BÃI ĐỖ XE – GIAI ĐOẠN 2

• Giảng viên: Nguyễn Hạnh Phúc - FIT - VMU
• Ngôn ngữ lập trình: C++ (Chuẩn C++11 trở lên)
• Chủ đề: Mảng tĩnh làm thuộc tính Lớp (Fixed Member Arrays), Quản lý Kích thước Vật lý vs Kích thước Logic, Thuật toán Dồn mảng và Xử lý Trùng lặp.

1 MỤC TIÊU & YÊU CẦU KỸ THUẬT

• Mục tiêu: Nâng cấp hệ thống quản lý bãi đỗ xe từ Giai đoạn 1 bằng cách thay thế toàn bộ các biến đối tượng lẻ (vehicle1, vehicle2, vehicle3 và lot1, lot2, lot3) bằng các Mảng tĩnh (Fixed-size Arrays).
• Hạn chế bắt buộc (Strict Constraints):
	1. ĐÓNG GÓI VÀ MẢNG TĨNH: Tất cả mảng lưu trữ phải là thuộc tính private có kích thước cố định (C-style array hoặc std::array).
	2. QUẢN LÝ KÍCH THƯỚC LOGIC: Phải quản lý song song hai khái niệm:
		• Sức chứa vật lý (Physical Capacity): Kích thước khai báo tối đa của mảng (MAX_VEHICLES = 3, MAX_LOTS = 10).
		• Kích thước logic (Logical Size / currentCount): Số lượng phần tử thực tế đang có trong mảng.
	3. THUẬT TOÁN DỒN MẢNG: Khi xóa một xe hoặc một bãi đỗ, bắt buộc phải dồn dịch các phần tử phía sau sang trái để danh sách dữ liệu trong mảng luôn liên tục từ chỉ số 0 đến currentCount - 1.
	4. CHƯA SỬ DỤNG CON TRỎ VÀ BỘ NHỚ ĐỘNG: Tuyệt đối KHÔNG dùng con trỏ (*), cấp phát động (new/delete), hay std::vector (các nội dung này sẽ triển khai ở Giai đoạn 3 và Giai đoạn 5).

2 CẤU TRÚC VÀ THIẾT KẾ NÂNG CẤP CÁC LỚP (CLASS SPECIFICATIONS)


2.1 Lớp 1: Vehicle (Giữ nguyên cấu trúc đóng gói từ Giai đoạn 1)

• Thuộc tính (private): vehicleID, vehicleType, entryTime, parkingDuration, parkingFee.
• Phương thức (public): Getters/Setters, calculateFee(), display().

2.2 Lớp 2: ParkingLot (Nâng cấp thuộc tính lưu trữ thành Mảng tĩnh)

• Thuộc tính (private):
	• int parkID: Mã định danh bãi đỗ xe.
	• char size: Kích thước bãi đỗ ('S' - Nhỏ [1 xe], 'M' - Trung bình [2 xe], 'L' - Lớn [3 xe]).
	• static const int MAX_VEHICLES = 3: Sức chứa vật lý tối đa của một bãi đỗ.
	• Vehicle vehicles[MAX_VEHICLES]: Mảng tĩnh chứa các đối tượng Vehicle.
	• int currentVehicleCount: Biến đếm số lượng xe thực tế đang đỗ (Kích thước logic, khởi tạo = 0).
• Phương thức (public):
	• Constructor mặc định và Constructor theo parkID, size.
	• bool isFull() const: Kiểm tra bãi đã đạt sức chứa tối đa tương ứng với size chưa.
	• bool addVehicle(const Vehicle& v): Thêm xe vào vị trí vehicles[currentVehicleCount] và tăng currentVehicleCount lên 1.
	• bool removeVehicle(int vID): Tìm xe theo ID trong mảng, xóa xe và dồn dịch mảng các phần tử phía sau sang trái, giảm currentVehicleCount đi 1.
	• int findVehicleIndex(int vID) const: Hàm bổ trợ trả về chỉ số (index) của xe trong mảng (trả về -1 nếu không tìm thấy).
	• void displayLotInfo() const: Duyệt mảng từ 0 đến currentVehicleCount - 1 để in thông tin bãi và danh sách xe.

2.3 Lớp 3: SystemInterface (Mở rộng quy mô quản lý 10 Bãi đỗ xe bằng Mảng)

• Thuộc tính (private):
	• static const int MAX_LOTS = 10: Mở rộng từ 3 bãi lên tối đa 10 bãi đỗ xe.
	• ParkingLot parkingLots[MAX_LOTS]: Mảng tĩnh chứa các đối tượng ParkingLot.
	• int currentLotCount: Số lượng bãi đỗ hiện có trong hệ thống (khởi tạo = 0).
• Phương thức (public):
	• void runMenu(): Điều khiển menu tương tác người dùng và xử lý ngoại lệ đầu vào khéo léo.
	• bool isParkIDExists(int pID) const: Kiểm tra ID bãi đỗ có bị trùng lặp trên mảng parkingLots hay không.
	• bool isVehicleIDExists(int vID) const: Duyệt qua toàn bộ các bãi đỗ trong mảng để kiểm tra ID xe có bị trùng lặp hay không.
	• int generateRandomID(): Hàm phụ trợ tự động sinh ID ngẫu nhiên bằng rand() khi người dùng nhập trùng ID.

3 CÁC QUY TẮC BỔ SUNG & XỬ LÝ MẢNG NÂNG CẤP

1. Quy tắc xếp xe tự động vào Mảng Bãi đỗ:
	• Khi thêm một xe mới, hệ thống tự động tìm bãi đỗ đầu tiên còn vị trí trống trong mảng parkingLots để xếp xe vào. Nếu tất cả các bãi đỗ hiện có đều đã đầy, thông báo cảnh báo ra màn hình.
2. Quy tắc xử lý Trùng lặp ID (Duplicate ID Handling):
	• Trùng ID Bãi đỗ: Nếu người dùng nhập parkID đã tồn tại trong mảng parkingLots, hiển thị cảnh báo và tự động gán một ID ngẫu nhiên cho bãi đỗ đó.
	• Trùng ID Xe: Nếu người dùng nhập vehicleID đã tồn tại ở bất kỳ bãi đỗ nào trong hệ thống, hiển thị cảnh báo và tự động gán một ID ngẫu nhiên cho xe đó.
3. Quy tắc Kiểm tra tính hợp lệ dữ liệu (Input Validation):
	• Nếu người dùng nhập sai kiểu dữ liệu (ví dụ: nhập chữ vào biến số), chương trình phải bắt lỗi std::cin.fail(), xóa cờ lỗi std::cin.clear(), loại bỏ bộ đệm std::cin.ignore() và yêu cầu nhập lại một cách an toàn.

4 DANH SÁCH CHỨC NĂNG MENU (MAIN MENU)

Chương trình hiển thị menu 9 chức năng chính (chưa tích hợp Đọc/Ghi File, chức năng này sẽ hoàn thiện ở bài kết thúc):
1. Tạo Bãi đỗ xe mới: Kiểm tra mảng parkingLots đã đạt MAX_LOTS (10 bãi) chưa. Nếu chưa, nhận parkID và size, kiểm tra trùng ID để gán ID ngẫu nhiên nếu cần.
2. Thêm xe vào bãi đỗ: Nhập vehicleID, vehicleType, entryTime, parkingDuration. Kiểm tra trùng ID xe toàn hệ thống. Tự động xếp xe vào bãi đỗ còn chỗ trống đầu tiên trong mảng.
3. Xóa một Bãi đỗ xe: Nhập parkID, tìm vị trí trong mảng parkingLots, xóa và dồn mảng bãi đỗ.
4. Lấy xe ra khỏi bãi đỗ: Nhập vehicleID, duyệt mảng tìm xe, xóa xe và dồn mảng xe bên trong bãi đỗ tương ứng.
5. Hiển thị danh sách tất cả các Bãi đỗ xe: Duyệt mảng parkingLots từ 0 đến currentLotCount - 1 để in tổng quan.
6. Hiển thị danh sách xe theo bãi cụ thể: Nhập parkID, duyệt mảng xe của bãi đó để in thông tin chi tiết.
7. Liệt kê xe theo loại phương tiện: Duyệt qua tất cả các bãi đỗ trong mảng parkingLots để lọc các xe khớp với vehicleType yêu cầu.
8. Tóm tắt phí đỗ xe trung bình: Lặp qua toàn bộ mảng dữ liệu để tính toán phí trung bình theo loại xe trên toàn hệ thống và phân chia theo từng bãi.
9. Thoát chương trình.
