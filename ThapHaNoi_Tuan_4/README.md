# Báo Cáo Bài Tập: Bài Toán Tháp Hà Nội - Tuần 4

## 1. Giới thiệu bài toán Tháp Hà Nội

* **Mục tiêu:** Di chuyển $n$ đĩa có kích thước khác nhau từ cọc nguồn **(A)** sang cọc đích **(C)**, sử dụng cọc phụ **(B)** làm trung gian.
* **Ràng buộc:**
  * Mỗi lần chỉ được phép di chuyển 1 đĩa nằm trên cùng của một cọc.
  * Không bao giờ được đặt một đĩa lớn hơn lên trên một đĩa nhỏ hơn.
* **Tổng số bước tối thiểu:** $2^n - 1$ bước.

---

## 2. Phương pháp 1: Cài đặt bằng Đệ quy

### 2.1. Ý tưởng giải thuật
Để chuyển $n$ đĩa từ cọc nguồn $A$ sang cọc đích $C$ lấy $B$ làm trung gian:
* **Bước cơ sở (Base case):** Khi $n = 1$, chuyển trực tiếp đĩa 1 từ $A$ sang $C$.
* **Bước đệ quy:**
  * **Bước 1:** Gọi đệ quy chuyển $n - 1$ đĩa trên cùng từ $A \to B$ (lấy $C$ làm trung gian).
  * **Bước 2:** Chuyển trực tiếp đĩa thứ $n$ từ $A \to C$.
  * **Bước 3:** Gọi đệ quy chuyển $n - 1$ đĩa từ $B \to C$ (lấy $A$ làm trung gian).

### 2.2. Đánh giá độ phức tạp
* **Thời gian (Time Complexity):** $O(2^n)$
* **Không gian (Space Complexity):** $O(n)$ (do độ sâu ngăn xếp gọi hàm - Call Stack của hệ thống)

---

## 3. Phương pháp 2: Cài đặt Khử Đệ quy bằng Stack 

### 3.1. Ý tưởng giải thuật
Giải thuật đệ quy sử dụng ngăn xếp hệ thống (Call Stack) để lưu lại các lời gọi hàm đang chờ. Khi khử đệ quy, ta tự định nghĩa một cấu trúc dữ liệu `Stack` để mô phỏng lại toàn bộ quá trình này.

Mỗi phần tử trong `Stack` lưu trữ trạng thái của một bài toán con:

```c
typedef struct {
    int n;          // Số lượng đĩa
    char from;      // Cọc nguồn
    char to;        // Cọc đích
    char aux;       // Cọc trung gian
} Task;
```

### 3.2. Cơ chế đảo ngược thứ tự đẩy vào Stack (LIFO)

Vì Stack hoạt động theo nguyên lý **Last In, First Out (LIFO)** — phần tử vào sau sẽ được lấy ra xử lý trước — nên khi phân rã một bài toán lớn ($n > 1$), các bài toán con phải được đẩy vào Stack theo **thứ tự ngược lại** so với trình tự thực thi:

1. **Đẩy công việc bước 3 vào trước:**  
   `push(n - 1, temp, to, from)` — Chuyển $n - 1$ đĩa từ trung gian về đích.
2. **Đẩy công việc bước 2 vào giữa:**  
   `push(1, from, to, temp)` — Chuyển đĩa thứ $n$ từ nguồn sang đích.
3. **Đẩy công việc bước 1 vào cuối cùng:**  
   `push(n - 1, from, temp, to)` — Chuyển $n - 1$ đĩa từ nguồn sang trung gian (để lấy ra xử lý ngay ở vòng lặp kế tiếp).

Vòng lặp tiếp tục lấy từng `Task` ra khỏi Stack xử lý cho đến khi Stack rỗng hoàn toàn.

### 3.3. Đánh giá độ phức tạp

* **Độ phức tạp thời gian (Time Complexity):** $O(2^n)$ (thực hiện tối ưu đúng $2^n - 1$ thao tác).
* **Độ phức tạp không gian (Space Complexity):** $O(n)$ (kích thước tối đa của cấu trúc `Stack` tương đương độ sâu đệ quy lớn nhất).

---

## 4. Test Cases kiểm thử giải thuật

Cả hai thuật toán (Đệ quy và Khử đệ quy bằng Stack) đều sinh chuỗi thao tác đồng nhất:

### Test Case 1: `n = 1`
* **Input:** `n = 1`, Nguồn: `A`, Đích: `C`, Trung gian: `B`
* **Output:**
  ```text
  Move disk from A to C
  ```

### Test Case 2: `n = 2` (Tổng số bước: $2^2 - 1 = 3$)
* **Input:** `n = 2`, Nguồn: `A`, Đích: `C`, Trung gian: `B`
* **Output:**
  ```text
  Move disk from A to B
  Move disk from A to C
  Move disk from B to C
  ```

### Test Case 3: `n = 3` (Tổng số bước: $2^3 - 1 = 7$)
* **Input:** `n = 3`, Nguồn: `A`, Đích: `C`, Trung gian: `B`
* **Output:**
  ```text
  Move disk from A to C
  Move disk from A to B
  Move disk from C to B
  Move disk from A to C
  Move disk from B to A
  Move disk from B to C
  Move disk from A to C
  ```