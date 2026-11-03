#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Xe{
	private:
		int maXe;
		string loaiXe;
		int gioVao;
		int thoiGianDo;
		double phiDoXe;
		bool dangChiemCho;
	public:
		Xe():maXe(0),loaiXe(""),gioVao(0),thoiGianDo(0),phiDoXe(0.0),dangChiemCho(false){}
		Xe(int ma, const string& loai, int gio, int thoiLuong){
			maXe = ma;
			loaiXe = loai;
			gioVao = gio;
			thoiGianDo = thoiLuong;
		}
		int layMaXe() const {return maXe;}  
		string layLoaiXe() const {return loaiXe;}
    	int layGioVao() const {return gioVao;}
    	int layThoiGianDo() const {return thoiGianDo;}
    	double layPhiDoXe() const {return phiDoXe;}
    	bool layDangChiemCho() const {return dangChiemCho;}
    	void ganMaXe(int ma) {maXe = ma;}
    	void ganLoaiXe(const string& loai) {loaiXe = loai;}
    	void ganGioVao(int gio) {gioVao = gio;}
    	void ganThoiLuongDo(int thoiLuong) {thoiGianDo = thoiLuong;}
    	void ganPhiDoXe(double phi) {phiDoXe = phi;}
    	void ganDangChiemCho(bool trangThai) {dangChiemCho = trangThai;}
    	static string chuanHoaLoaiXe(const string& loai){
    		string loai2 = loai;
    		loai2[0]=toupper(loai[0]);
    		for (int i=1;i<loai.length();i++) loai2[i]=tolower(loai[i]);
    		return loai2;
		}
		static bool laLoaiXeHopLe(const string& loai, const int& vao, const int& tg){
			vector<string> ds = {"Car", "Motorcycle", "Bicycle"};
			if (find(ds.begin(),ds.end(),loai) == ds.end()) return false;
			else if (!(0 <= vao && vao <=23)) return false;
			else if (!(0 <= tg && tg <=23))	return false;
			return true;
		} 
		void tinhPhiDoXe(){
			double phi=0;
			double phi_h;
			if (chuanHoaLoaiXe(loaiXe) == "Car") phi_h = 6;
			else if (chuanHoaLoaiXe(loaiXe) == "Motorcycle") phi_h = 4;
			else if (chuanHoaLoaiXe(loaiXe) == "Bicycle") phi_h = 2;
			for (int i = 1; i <= thoiGianDo; i++){
				if (i == 1 || i ==2){
					if (((gioVao + i) % 24) >= 6 && ((gioVao + i) % 24) <= 10) phi += phi_h*(130.0/100.0);
					else if (((gioVao + i) % 24) >= 15 && ((gioVao + i) % 24) <= 19) phi += phi_h*(95.0/100.0);
					else phi += phi_h;
				}
				else phi += phi_h*(90.0/100.0);
			}
			ganPhiDoXe(phi);
		}
		void hienThi() const{
			if (laLoaiXeHopLe(loaiXe, gioVao, thoiGianDo)){
				cout << "Ma xe: " << layMaXe() << endl;
				cout << "Loai xe: " << layLoaiXe() << endl;
				cout << "Gio vao: " << layGioVao() << endl;
				cout << "Thoi gian do" << layThoiGianDo() << endl;
				cout << "Phi do xe: " << layPhiDoXe() << endl;
				if (dangChiemCho) cout << "Da chiem cho" << endl;
				else cout << "Chua chiem cho" << endl;
			}
			else cout << "Khong hop le" << endl;
		}
};
class baiDo{
	int maBai;
	char kichThuoc;
	Xe xe1, xe2, xe3;
	bool trangThaiXe1 = true, trangThaiXe2 = true, trangThaiXe3 = true;
	public:
		baiDo():maBai(0),kichThuoc(' '){}
		baiDo(int ma, const char& kt){
			maBai = ma;
			kichThuoc = kt;
		}
		int layMaBai() const {return maBai;}  
		char layKichThuoc() const {return kichThuoc;}
		bool layTrangThaiXe1() {return trangThaiXe1;}
		bool layTrangThaiXe2() {return trangThaiXe2;}
		bool layTrangThaiXe3() {return trangThaiXe3;}
    	void ganMaBai(int ma) {maBai = ma;}
    	void ganKichThuoc(const char& kt) {kichThuoc = kt;}
    	void hienthiXe(){
    		if (!layTrangThaiXe1()) cout << xe1.layMaXe() << " - " << xe1.layLoaiXe() << " - " << xe1.layGioVao() << " - " << xe1.layThoiGianDo() << " - " << xe1.layPhiDoXe() << endl;
    		if (!layTrangThaiXe2()) cout << xe2.layMaXe() << " - " << xe2.layLoaiXe() << " - " << xe2.layGioVao() << " - " << xe2.layThoiGianDo() << " - " << xe2.layPhiDoXe() << endl;
    		if (!layTrangThaiXe3()) cout << xe3.layMaXe() << " - " << xe3.layLoaiXe() << " - " << xe3.layGioVao() << " - " << xe3.layThoiGianDo() << " - " << xe3.layPhiDoXe() << endl;
    		if (layTrangThaiXe1() && layTrangThaiXe2() && layTrangThaiXe3()) cout << "Khong co xe!" << endl;
		}
		bool hienthiXeTheoLoai(string loai){
    		if (loai == xe1.layLoaiXe()) cout << xe1.layMaXe() << " - " << xe1.layLoaiXe() << " - " << xe1.layGioVao() << " - " << xe1.layThoiGianDo() << " - " << xe1.layPhiDoXe() << endl;
    		if (loai == xe2.layLoaiXe()) cout << xe2.layMaXe() << " - " << xe2.layLoaiXe() << " - " << xe2.layGioVao() << " - " << xe2.layThoiGianDo() << " - " << xe2.layPhiDoXe() << endl;
    		if (loai == xe3.layLoaiXe()) cout << xe3.layMaXe() << " - " << xe3.layLoaiXe() << " - " << xe3.layGioVao() << " - " << xe3.layThoiGianDo() << " - " << xe3.layPhiDoXe() << endl;
    		if (loai != xe1.layLoaiXe() && loai != xe2.layLoaiXe() && loai != xe3.layLoaiXe()) return false;
    		return true;
		}
		bool themXe(const Xe& x){
			if (trangThaiXe1){
				xe1.ganMaXe(x.layMaXe());
				xe1.ganLoaiXe(x.layLoaiXe());
				xe1.ganGioVao(x.layGioVao());
				xe1.ganThoiLuongDo(x.layThoiGianDo());
				xe1.tinhPhiDoXe();
				xe1.ganDangChiemCho(true);
				trangThaiXe1 = false;
			}
			else if (trangThaiXe2 && (kichThuoc == 'M' || kichThuoc == 'L')){
				xe2.ganMaXe(x.layMaXe());
				xe2.ganLoaiXe(x.layLoaiXe());
				xe2.ganGioVao(x.layGioVao());
				xe2.ganThoiLuongDo(x.layThoiGianDo());
				xe2.tinhPhiDoXe();
				xe2.ganDangChiemCho(true);
				trangThaiXe2 = false;
			}
			else if (trangThaiXe3 && kichThuoc == 'L'){
				xe3.ganMaXe(x.layMaXe());
				xe3.ganLoaiXe(x.layLoaiXe());
				xe3.ganGioVao(x.layGioVao());
				xe3.ganThoiLuongDo(x.layThoiGianDo());
				xe3.tinhPhiDoXe();
				xe3.ganDangChiemCho(true);
				trangThaiXe3 = false;
			}
			else return false;
			return true;
		}
		bool xoaXe(int vID){
			if (xe1.layMaXe() == vID) {
				xe1 = Xe();
				trangThaiXe1 = true;
				return true;
			}
			if (xe2.layMaXe() == vID) {
				xe2 = Xe();
				trangThaiXe2 = true;
				return true;
			}
			if (xe3.layMaXe() == vID) {
				xe3 = Xe();
				trangThaiXe3 = true;
				return true;
			}
			return false;
		}
		void hienThi(){
			cout << "ID bai: " << maBai << endl;
			cout << "Kich thuoc:  " << kichThuoc << endl;
			cout << "Danh sach xe hien co:" << endl;
			if (!trangThaiXe1) {cout << xe1.layMaXe() << " " << xe1.layLoaiXe() << " "  << xe1.layGioVao() << " "  << xe1.layThoiGianDo() << endl;}
			if (!trangThaiXe2) {cout << xe2.layMaXe() << " " << xe2.layLoaiXe() << " "  << xe2.layGioVao() << " "  << xe2.layThoiGianDo() << endl;}
			if (!trangThaiXe3) {cout << xe3.layMaXe() << " " << xe3.layLoaiXe() << " "  << xe3.layGioVao() << " "  << xe3.layThoiGianDo() << endl;}
		}
};
class dieuHanhHeThong{
	baiDo bai1, bai2, bai3;
	bool trangThaiBai1, trangThaiBai2, trangThaiBai3;
	public:
		dieuHanhHeThong():trangThaiBai1(true),trangThaiBai2(true),trangThaiBai3(true){}
		dieuHanhHeThong(bool trangThaiBai1,bool trangThaiBai2,bool trangThaiBai3){
			trangThaiBai1 = trangThaiBai1;
			trangThaiBai2 = trangThaiBai2;
			trangThaiBai3 = trangThaiBai3;
		}
		bool layTrangThaiBai1() {return trangThaiBai1;}
		bool layTrangThaiBai2() {return trangThaiBai2;}
		bool layTrangThaiBai3() {return trangThaiBai3;}
		void ganTrangThaiBai1(bool trangThai1) {trangThaiBai1 = trangThai1;}
		void ganTrangThaiBai2(bool trangThai2) {trangThaiBai2 = trangThai2;}
		void ganTrangThaiBai3(bool trangThai3) {trangThaiBai3 = trangThai3;}
		static int main(){
			dieuHanhHeThong dhht;
			int yeucau;
			do{
				cout << "_____________________________________________" << endl;
				cout << "Chon 1 trong cac chuc nang sau:" << endl;
				cout << "1.Tao bai do xe moi" << endl;
				cout << "2.Them xe vao bai do" << endl;
				cout << "3.Xoa mot bai do xe" << endl;
				cout << "4.Lay xe ra khoi bai do" << endl;
				cout << "5.Hien thi danh sach tat ca cac bai do xe" << endl;
				cout << "6.Hien thi danh sach xe theo bai cu the" << endl;
				cout << "7.Liet ke xe theo loai phuong tien" << endl;
				cout << "8.Xem bao cao tom tat phi do xe trung binh" << endl;
				cout << "9.Thoat chuong trinh" << endl;
				cout << "_____________________________________________" << endl;
				cout << "Chon cac chuc nang (1-9): ";
				cin >> yeucau;
				dhht.chayMenu(yeucau);
				cout << endl;
			}while (yeucau!=9);
			cout << "Da thoat chuong trinh...";
		}
		void chayMenu(int yc){
			switch (yc){
				case 1:{
					int ma;
					char kt;
					if (layTrangThaiBai1()){
						cout << "Nhap ma bai do xe: ";
						cin >> ma;
						cout << "Nhap kich thuoc bai do xe: ";
						cin >> kt;
						ganTrangThaiBai1(false);
						bai1 = baiDo(ma, kt); 
						cout << "Tao thanh cong!" << endl;
					}
					else if (layTrangThaiBai2()){
						cout << "Nhap ma bai do xe: ";
						cin >> ma;
						cout << "Nhap kich thuoc bai do xe: ";
						cin >> kt;
						if (ma == bai1.layMaBai()){
							cout << "Tao that bai do trung ma bai" << endl;
							break;
						}
						ganTrangThaiBai2(false);
						bai2 = baiDo(ma, kt);
						cout << "Tao thanh cong!" << endl;
					}
					else if (layTrangThaiBai3()){
						cout << "Nhap ma bai do xe: ";
						cin >> ma;
						cout << "Nhap kich thuoc bai do xe: ";
						cin >> kt;
						if (ma == bai1.layMaBai() || ma == bai2.layMaBai()){
							cout << "Tao that bai do trung ma bai" << endl;
							break;
						}
						ganTrangThaiBai3(false);
						bai3 = baiDo(ma, kt);
						cout << "Tao thanh cong!" << endl;
					}
					else cout << "Khong the tao them bai do xe nua!" << endl;
					break;
				}
				case 2:{
					int maXe, gioVao, thoiGianDo;
					string loaiXe;
					cout << "Nhap ma xe: ";
					cin >> maXe;
					cout << "Nhap loai xe: ";
					cin >> loaiXe;
					cout << "Nhap gio vao: ";
					cin >> gioVao;
					cout << "Nhap thoi gian do: ";
					cin >> thoiGianDo;
					Xe x(maXe, loaiXe, gioVao, thoiGianDo);
					if (bai1.themXe(x)){
						cout << "Xep xe thanh cong!" << endl;
					}
					else if (bai2.themXe(x)){
						cout << "Xep xe thanh cong!" << endl;
					}
					else if (bai3.themXe(x)){
						cout << "Xep xe thanh cong!" << endl;
					}
					else{
						cout << "Xep xe that bai!" << endl;
					}				
					break;
				}
				case 3:{
					int ma;
					cout << "Nhap ma bai do xe: ";
					cin >> ma;
					if (ma == bai1.layMaBai()){
						bai1 = baiDo();
						ganTrangThaiBai1(true);
						cout << "Xoa bai do xe thanh cong!" << endl;
					}
					else if (ma == bai2.layMaBai()){
						bai2 = baiDo();
						ganTrangThaiBai2(true);
						cout << "Xoa bai do xe thanh cong!" << endl;
					}
					else if (ma == bai3.layMaBai()){
						bai3 = baiDo();
						ganTrangThaiBai3(true);
						cout << "Xoa bai do xe thanh cong!" << endl;
					}
					else cout << "Khong thay bai do xe!" << endl;
					break;
				}
				case 4:{
					int ma;
					cout << "Nhap ma xe: ";
					cin >> ma;
					if (!layTrangThaiBai1() && bai1.xoaXe(ma)){
						cout << "Da lay xe ra khoi bai!" << endl;
					}
					else if (!layTrangThaiBai2() && bai2.xoaXe(ma)){
						cout << "Da lay xe ra khoi bai!" << endl;
					}
					else if (!layTrangThaiBai3() && bai3.xoaXe(ma)){
						cout << "Da lay xe ra khoi bai!" << endl;
					}
					else cout << "Khong thay xe!" << endl;
					break;
				}
				case 5:{
					cout << "Tat ca cac bai do (ma bai - kich thuoc - so xe): " << endl;
					if (!layTrangThaiBai1()){
						cout << bai1.layMaBai() << " - " << bai1.layKichThuoc() << " - " << (bai1.layTrangThaiXe1() == false) + (bai1.layTrangThaiXe2() == false) + (bai1.layTrangThaiXe2() == false) << endl;
					}
					if (!layTrangThaiBai2()){
						cout << bai2.layMaBai() << " - " << bai2.layKichThuoc() << " - " << (bai2.layTrangThaiXe1() == false) + (bai2.layTrangThaiXe2() == false) + (bai2.layTrangThaiXe3() == false) << endl;
					}
					if (!layTrangThaiBai3()){
						cout << bai3.layMaBai() << " - " << bai3.layKichThuoc() << " - " << (bai3.layTrangThaiXe1() == false) + (bai3.layTrangThaiXe2() == false) + (bai3.layTrangThaiXe3() == false) << endl;
					}
					if (layTrangThaiBai1() && layTrangThaiBai2() && layTrangThaiBai3()) cout << "Khong co!" << endl;
					break;
				}
				case 6:{
					int ma;
					cout << "Nhap ma bai do xe: ";
					cin >> ma;
					if (ma == bai1.layMaBai()){
						bai1.hienthiXe();
					}
					else if (ma == bai2.layMaBai()){
						bai2.hienthiXe();
					}
					else if (ma == bai3.layMaBai()){
						bai3.hienthiXe();
					}
					else cout << "Khong tim thay bai do xe!" << endl;
					break;
				}
				case 7:{
					string loai;
					cout << "Nhap loai xe: ";
					cin >> loai;
					loai = Xe::chuanHoaLoaiXe(loai);
					cout << "Tat ca cac " << loai << endl;
					if (!bai1.hienthiXeTheoLoai(loai) && !bai2.hienthiXeTheoLoai(loai) && !bai3.hienthiXeTheoLoai(loai)) cout << "Khong co xe!" << endl;
					break;
				}
				case 8:{
					cout << "1. Muc gia tung loai xe: " << endl;
					cout << "Car: $6.00/h" << endl;
					cout << "Motorcycle: $4.00/h" << endl;
					cout << "Bicycle: $2.00/h" << endl;
					cout << "2. Khung gio cao diem: " << endl;
					cout << "Khung gio sang: 6, 7, 8, 9" << endl;
					cout << "Khung gio chieu: 15, 16, 17, 18" << endl;
					cout << "3. Cong thuc tinh phi: " << endl;
					cout << "   Trong 2 gio dau:" << endl;
					cout << "      Neu vao gio cao diem: +30% so voi don gia chuan" << endl;
					cout << "      Neu vao gio thap diem: -5% so voi don gia chuan" << endl;
					cout << "   Tu gio thu 3:" << endl;
					cout << "      -10% bat ke gio nao" << endl;
					break;
				}
				case 9: break;
				default: cout << "Cu phap khong hop le!";
			}
		}
};
int main(){
	dieuHanhHeThong dh;
	dh.main();
}
