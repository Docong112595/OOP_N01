#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int nhap_so_nguyen(string thong_bao) {
    int x;
    while (true) {
        cout << thong_bao;
        cin >> x;

        if (cin.fail()) {
            cout << "Du lieu khong hop le. Hay nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
    }
}

class phuong_tien {
private:
    int ma_xe;
    string loai_xe;
    int gio_vao;
    int tg_do;
    double parkingFee;

public:
    phuong_tien();
    phuong_tien(int ma, string loai, int gio, int tg);

    int lay_ma_xe() const;
    string lay_loai_xe() const;

    void set_ma_xe(int ma);
    void set_loai_xe(string loai);
    void set_gio_vao(int gio);
    void set_tg_do(int tg);

    double tinh_phi() const;
    void hien_thi() const;
};

phuong_tien::phuong_tien()
    : ma_xe(0), loai_xe(""), gio_vao(0), tg_do(0), parkingFee(0) {
}

phuong_tien::phuong_tien(int ma, string loai, int gio, int tg)
    : ma_xe(ma), loai_xe(loai), gio_vao(gio), tg_do(tg), parkingFee(0) {
    parkingFee = tinh_phi();
}

int phuong_tien::lay_ma_xe() const {
    return ma_xe;
}

string phuong_tien::lay_loai_xe() const {
    return loai_xe;
}

void phuong_tien::set_ma_xe(int ma) {
    ma_xe = ma;
}

void phuong_tien::set_loai_xe(string loai) {
    loai_xe = loai;
    parkingFee = tinh_phi();
}

void phuong_tien::set_gio_vao(int gio) {
    gio_vao = gio;
    parkingFee = tinh_phi();
}

void phuong_tien::set_tg_do(int tg) {
    tg_do = tg;
    parkingFee = tinh_phi();
}

double phuong_tien::tinh_phi() const {
    double gia;

    if (loai_xe == "Car") {
        gia = 6.0;
    } else if (loai_xe == "Motorcycle") {
        gia = 4.0;
    } else {
        gia = 2.0;
    }

    bool cao_diem = (gio_vao >= 6 && gio_vao <= 9)
                 || (gio_vao >= 15 && gio_vao <= 18);

    double tong = 0;

    for (int h = 0; h < tg_do; h++) {
        if (h < 2) {
            if (cao_diem) {
                tong += gia * 1.30;
            } else {
                tong += gia * 0.95;
            }
        } else {
            tong += gia * 0.90;
        }
    }

    return tong;
}

void phuong_tien::hien_thi() const {
    cout << "  ID: " << ma_xe
         << " | " << loai_xe
         << " | " << gio_vao << "h"
         << " | " << tg_do << "h"
         << " | Phi: $" << fixed << setprecision(2) << parkingFee << "\n";
}

class bai_xe {
private:
    int ma_bai;
    char kich_thuoc;

    static const int MAX_VEHICLES = 3;
    phuong_tien vehicles[MAX_VEHICLES];
    int currentVehicleCount;

public:
    bai_xe();
    bai_xe(int ma, char kt);

    int lay_ma() const;
    bool isFull() const;
    bool them(phuong_tien v);
    bool xoa(int ma_xe);
    bool chua(int ma_xe) const;
    int findVehicleIndex(int ma_xe) const;
    void hien_thi() const;
    bool co_loai(string loai, int& dem, double& tong) const;
    void liet_ke_loai(string loai) const;
};

bai_xe::bai_xe()
    : ma_bai(0), kich_thuoc('S'), currentVehicleCount(0) {
}

bai_xe::bai_xe(int ma, char kt)
    : ma_bai(ma), kich_thuoc(kt), currentVehicleCount(0) {
}

int bai_xe::lay_ma() const {
    return ma_bai;
}

bool bai_xe::isFull() const {
    int suc_chua;

    if (kich_thuoc == 'S') {
        suc_chua = 1;
    } else if (kich_thuoc == 'M') {
        suc_chua = 2;
    } else {
        suc_chua = 3;
    }

    return currentVehicleCount >= suc_chua;
}

bool bai_xe::them(phuong_tien v) {
    if (isFull()) {
        return false;
    }

    vehicles[currentVehicleCount] = v;
    currentVehicleCount++;
    return true;
}

int bai_xe::findVehicleIndex(int ma_xe) const {
    for (int i = 0; i < currentVehicleCount; i++) {
        if (vehicles[i].lay_ma_xe() == ma_xe) {
            return i;
        }
    }

    return -1;
}

bool bai_xe::xoa(int ma_xe) {
    int vi_tri = findVehicleIndex(ma_xe);

    if (vi_tri == -1) {
        return false;
    }

    // Don cac xe phia sau sang trai
    for (int i = vi_tri; i < currentVehicleCount - 1; i++) {
        vehicles[i] = vehicles[i + 1];
    }

    currentVehicleCount--;
    return true;
}

bool bai_xe::chua(int ma_xe) const {
    return findVehicleIndex(ma_xe) != -1;
}

void bai_xe::hien_thi() const {
    cout << "Bai " << ma_bai << " [" << kich_thuoc << "] "
         << currentVehicleCount << "/";

    if (kich_thuoc == 'S') {
        cout << 1;
    } else if (kich_thuoc == 'M') {
        cout << 2;
    } else {
        cout << 3;
    }

    cout << " xe\n";

    for (int i = 0; i < currentVehicleCount; i++) {
        vehicles[i].hien_thi();
    }
}

bool bai_xe::co_loai(string loai, int& dem, double& tong) const {
    dem = 0;
    tong = 0;

    for (int i = 0; i < currentVehicleCount; i++) {
        if (vehicles[i].lay_loai_xe() == loai) {
            dem++;
            tong += vehicles[i].tinh_phi();
        }
    }

    return dem > 0;
}

void bai_xe::liet_ke_loai(string loai) const {
    for (int i = 0; i < currentVehicleCount; i++) {
        if (vehicles[i].lay_loai_xe() == loai) {
            vehicles[i].hien_thi();
        }
    }
}

class SystemInterface {
private:
    static const int MAX_LOTS = 10;
    bai_xe parkingLots[MAX_LOTS];
    int currentLotCount;

    bool isParkIDExists(int ma_bai) const;
    bool isVehicleIDExists(int ma_xe) const;
    int generateRandomID() const;

public:
    SystemInterface();
    void runMenu();
};

SystemInterface::SystemInterface() : currentLotCount(0) {
}

bool SystemInterface::isParkIDExists(int ma_bai) const {
    for (int i = 0; i < currentLotCount; i++) {
        if (parkingLots[i].lay_ma() == ma_bai) {
            return true;
        }
    }

    return false;
}

bool SystemInterface::isVehicleIDExists(int ma_xe) const {
    for (int i = 0; i < currentLotCount; i++) {
        if (parkingLots[i].chua(ma_xe)) {
            return true;
        }
    }

    return false;
}

int SystemInterface::generateRandomID() const {
    return rand() % 90000 + 10000;
}

void SystemInterface::runMenu() {
    int chon;

    while (true) {
        cout << "\n===== QUAN LY BAI DO XE =====\n";
        cout << "1. Tao bai do\n";
        cout << "2. Them xe\n";
        cout << "3. Xoa bai do\n";
        cout << "4. Lay xe ra\n";
        cout << "5. Hien thi tat ca bai do\n";
        cout << "6. Hien thi xe theo bai\n";
        cout << "7. Liet ke xe theo loai\n";
        cout << "8. Bao cao phi trung binh\n";
        cout << "9. Thoat\n";

        chon = nhap_so_nguyen("Chon: ");

        switch (chon) {
        case 1: {
            if (currentLotCount >= MAX_LOTS) {
                cout << "He thong da du 10 bai xe!\n";
                break;
            }

            int ma = nhap_so_nguyen("Ma bai: ");

            if (isParkIDExists(ma)) {
                cout << "Ma bai bi trung. He thong tu tao ma moi.\n";
                do {
                    ma = generateRandomID();
                } while (isParkIDExists(ma));
            }

            char kt;
            while (true) {
                cout << "Kich thuoc (S/M/L): ";
                cin >> kt;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (kt == 'S' || kt == 'M' || kt == 'L') {
                    break;
                }

                cout << "Kich thuoc khong hop le. Hay nhap lai!\n";
            }

            parkingLots[currentLotCount] = bai_xe(ma, kt);
            currentLotCount++;
            cout << "Da tao bai " << ma << "\n";
            break;
        }

        case 2: {
            if (currentLotCount == 0) {
                cout << "Chua co bai do. Hay tao bai truoc!\n";
                break;
            }

            int ma = nhap_so_nguyen("Ma xe: ");

            if (isVehicleIDExists(ma)) {
                cout << "Ma xe bi trung. He thong tu tao ma moi.\n";
                do {
                    ma = generateRandomID();
                } while (isVehicleIDExists(ma));
            }

            string loai;
            while (true) {
                cout << "Loai (Car/Motorcycle/Bicycle): ";
                cin >> loai;

                if (loai == "Car" || loai == "Motorcycle"
                    || loai == "Bicycle") {
                    break;
                }

                cout << "Loai xe khong hop le. Hay nhap lai!\n";
            }

            int gio;
            do {
                gio = nhap_so_nguyen("Gio vao (0-23): ");
                if (gio < 0 || gio > 23) {
                    cout << "Gio vao phai tu 0 den 23!\n";
                }
            } while (gio < 0 || gio > 23);

            int tg;
            do {
                tg = nhap_so_nguyen("Thoi luong (1-23): ");
                if (tg < 1 || tg > 23) {
                    cout << "Thoi luong phai tu 1 den 23!\n";
                }
            } while (tg < 1 || tg > 23);

            phuong_tien v(ma, loai, gio, tg);
            bool da_them = false;

            // Them vao bai dau tien con cho
            for (int i = 0; i < currentLotCount; i++) {
                if (parkingLots[i].them(v)) {
                    da_them = true;
                    break;
                }
            }

            if (da_them) {
                cout << "Da them xe " << ma
                     << " | Phi: $" << fixed << setprecision(2)
                     << v.tinh_phi() << "\n";
            } else {
                cout << "Tat ca bai do da day!\n";
            }

            break;
        }

        case 3: {
            int ma = nhap_so_nguyen("Ma bai can xoa: ");
            int vi_tri = -1;

            for (int i = 0; i < currentLotCount; i++) {
                if (parkingLots[i].lay_ma() == ma) {
                    vi_tri = i;
                    break;
                }
            }

            if (vi_tri == -1) {
                cout << "Khong tim thay bai do!\n";
                break;
            }

            // Don cac bai phia sau sang trai
            for (int i = vi_tri; i < currentLotCount - 1; i++) {
                parkingLots[i] = parkingLots[i + 1];
            }

            currentLotCount--;
            cout << "Da xoa bai " << ma << "\n";
            break;
        }

        case 4: {
            int ma = nhap_so_nguyen("Ma xe can lay ra: ");
            bool da_xoa = false;

            for (int i = 0; i < currentLotCount; i++) {
                if (parkingLots[i].xoa(ma)) {
                    da_xoa = true;
                    break;
                }
            }

            cout << (da_xoa ? "Da lay xe ra\n" : "Khong tim thay xe\n");
            break;
        }

        case 5: {
            if (currentLotCount == 0) {
                cout << "Chua co bai do nao!\n";
            }

            for (int i = 0; i < currentLotCount; i++) {
                parkingLots[i].hien_thi();
            }

            break;
        }

        case 6: {
            int ma = nhap_so_nguyen("Ma bai: ");
            bool tim_thay = false;

            for (int i = 0; i < currentLotCount; i++) {
                if (parkingLots[i].lay_ma() == ma) {
                    parkingLots[i].hien_thi();
                    tim_thay = true;
                    break;
                }
            }

            if (!tim_thay) {
                cout << "Khong tim thay bai do!\n";
            }

            break;
        }

        case 7: {
            string loai;
            cout << "Loai xe (Car/Motorcycle/Bicycle): ";
            cin >> loai;

            bool tim_thay = false;

            for (int i = 0; i < currentLotCount; i++) {
                int dem;
                double tong;

                if (parkingLots[i].co_loai(loai, dem, tong)) {
                    cout << "Bai " << parkingLots[i].lay_ma() << ":\n";
                    parkingLots[i].liet_ke_loai(loai);
                    tim_thay = true;
                }
            }

            if (!tim_thay) {
                cout << "Khong co xe thuoc loai nay!\n";
            }

            break;
        }

        case 8: {
            string loai_arr[3] = {"Car", "Motorcycle", "Bicycle"};

            for (int t = 0; t < 3; t++) {
                int tong_dem = 0;
                double tong_phi = 0;

                cout << "\n--- " << loai_arr[t] << " ---\n";

                for (int i = 0; i < currentLotCount; i++) {
                    int dem;
                    double tong;

                    parkingLots[i].co_loai(loai_arr[t], dem, tong);

                    if (dem > 0) {
                        cout << "Bai " << parkingLots[i].lay_ma()
                             << ": " << dem << " xe"
                             << " | Tong phi: $" << fixed
                             << setprecision(2) << tong << "\n";
                    }

                    tong_dem += dem;
                    tong_phi += tong;
                }

                if (tong_dem == 0) {
                    cout << "Toan he thong: khong co xe\n";
                } else {
                    cout << "Toan he thong: " << tong_dem
                         << " xe | Phi trung binh: $"
                         << fixed << setprecision(2)
                         << tong_phi / tong_dem << "\n";
                }
            }

            break;
        }

        case 9:
            cout << "Ket thuc chuong trinh!\n";
            return;

        default:
            cout << "Lua chon khong hop le. Hay chon tu 1 den 9!\n";
        }
    }
}

int main() {
    srand((unsigned int)time(0));

    SystemInterface sys;
    sys.runMenu();

    return 0;
}
