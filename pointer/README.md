# Hướng dẫn sử dụng
Đây là hướng dẫn sử dụng trên Linux. Nếu bạn sử dụng
Dev-C, copy mã nguồn vào Dev-C và dịch trên Dev-C.
## 2darray.c
- Truyền tham số ma trận cho hàm, với ma trận có
kích thước cố định. Với cách tổ chức này, vùng nhớ
của ma trận *liên tục*.
- Cách dịch: gcc 2darray.c -o 2darray
- Cách thực hiện: ./2darray matrix.txt
- Lưu ý: matrix.txt có 3 dòng, mỗi dòng có 2 số thực

## arraypointer.c
- Truyền tham số ma trận cho hàm với ma trận được
tổ chức theo kiểu mảng (kích thước xác định trước)
đến các con trỏ. Với cách tổ chức này, vùng nhớ của
ma trận sẽ *không liên tục*.
- Cách dịch: gcc arraypointer.c -o arraypointer
- Cách thực hiện: ./arraypointer matrix.txt
- Lưu ý: matrix.txt có 3 dòng, mỗi dòng có 2 số thực.
Với mục đích thử nghiệm, khi chương trình hỏi nhập số n,
ta nhập số 2. Nếu muốn nhập số khác, cần tạo file ma trận
mới với kích thước khác.

## ppointer.c
- Tổ chức ma trận theo kiểu con trỏ đến con trỏ, nhưng
vùng nhớ của ma trận được cấp phát liên tục. Trong ba
cách cấp phát bộ nhớ, cách này là mềm dẻo nhất đồng
thời vẫn đảm bảo vùng nhớ của ma trận được liên tục.
- Cách dịch: gcc ppointer.c -o arraypointer
- Cách thực hiện: ./ppointer matrix.txt
- Lưu ý: matrix.txt có 3 dòng, mỗi dòng có 2 số thực.
Với mục đích thử nghiệm, khi chương trình hỏi nhập số n,
ta nhập số 2. Nếu muốn nhập số khác, cần tạo file ma trận
mới với kích thước khác.
