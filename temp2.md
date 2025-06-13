Dưới đây là ý tưởng phát triển chi tiết cho dự án bài tập lớn ở trường đại học:

**1. Mô tả tổng quan:**

- Ứng dụng web sàn thương mại điện tử bán đồ cũ, cho phép người dùng đăng bán, mua, trả giá, thanh toán và xác nhận giao dịch.
- Công nghệ: Spring Boot (backend), ReactJS (frontend), MongoDB Atlas (database), tích hợp thanh toán MoMo.

**2. Các chức năng chính:**

- **Đăng ký/Đăng nhập:** Hỗ trợ xác thực qua email, phân quyền người dùng (người mua/người bán).
- **Quản lý sản phẩm:** Người bán đăng bán sản phẩm, mô tả, hình ảnh, giá, cho phép hoặc không cho phép trả giá, thiết lập khoảng giá trả giá.
- **Tìm kiếm & duyệt sản phẩm:** Người mua tìm kiếm, lọc, xem chi tiết sản phẩm.
- **Trả giá:** Nếu sản phẩm cho phép trả giá, người mua gửi đề nghị giá mới trong khoảng cho phép. Hệ thống gửi email thông báo cho người bán. Nếu người bán không phản hồi trong 24 giờ hoặc sau khi người mua trả giá và được người bán xác nhận nhưng không phản hồi hệ thống tự động từ chối giá.
- **Xác nhận giá:** Người bán có thể chấp nhận hoặc từ chối giá đề nghị. Nếu chấp nhận, hệ thống gửi email xác nhận cho người mua.
- **Thanh toán:** Người mua thanh toán qua MoMo. Sàn giữ tiền và tính phí giao dịch.
- **Xác nhận nhận hàng:** Sau khi nhận hàng, người mua xác nhận, sàn chuyển tiền cho người bán (sau khi trừ phí).
- **Quản lý giao dịch:** Lịch sử giao dịch, trạng thái giao dịch (đang trả giá, chờ thanh toán, chờ nhận hàng, hoàn thành).
- **Thông báo qua email:** Gửi thông báo các bước quan trọng (trả giá, xác nhận giá, thanh toán, xác nhận nhận hàng).
- **Quản trị viên:** Quản lý người dùng, sản phẩm, giao dịch, xử lý khiếu nại, thống kê hệ thống, quản lý dòng tiền.
- **Xử lý khiếu nại:** Người mua có thể gửi khiếu nại nếu sản phẩm không đúng mô tả, bị hư hỏng, hoặc không nhận được hàng. Hệ thống lưu trữ thông tin khiếu nại và hỗ trợ xử lý tranh chấp.
- **Đăng tải ảnh, video:** 
  - Người bán có thể đăng tải nhiều ảnh và video khi đăng bán sản phẩm để tăng độ tin cậy.
  - Khi người bán đóng gói sản phẩm để giao hàng, phải đăng tải ảnh/video quá trình đóng gói lên hệ thống.
  - Khi người mua nhận hàng, phải quay video unbox (mở hộp) và đăng tải lên hệ thống để kiểm tra tình trạng sản phẩm, làm bằng chứng trong trường hợp phát sinh khiếu nại và để xác nhận giao dịch (sàn sẽ chuyển tiền về cho người bán).

**3. Kiến trúc hệ thống:**

- **Backend (Spring Boot):**
  - RESTful API cho các chức năng trên.
  - Kết nối MongoDB Atlas để lưu trữ dữ liệu người dùng, sản phẩm, giao dịch.
  - Tích hợp email (JavaMailSender).
  - Tích hợp MoMo Payment Gateway.
  - **Chức năng quản trị:** API cho phép quản trị viên quản lý người dùng, sản phẩm, giao dịch, xử lý khiếu nại.
  - **Xử lý media:** API hỗ trợ upload, lưu trữ và truy xuất ảnh/video sản phẩm, ảnh/video đóng gói, video unbox.
- **Frontend (ReactJS):**
  - Giao diện người dùng thân thiện, responsive.
  - Các trang: Đăng nhập/Đăng ký, Trang chủ, Quản lý sản phẩm, Chi tiết sản phẩm, Trả giá, Thanh toán, Lịch sử giao dịch.
  - **Trang quản trị viên:** Giao diện riêng cho quản trị viên với các chức năng:
    - Quản lý danh sách người dùng (xem, khóa/mở khóa tài khoản).
    - Quản lý sản phẩm (duyệt/xóa sản phẩm vi phạm).
    - Quản lý giao dịch (xem chi tiết, xử lý tranh chấp).
    - Thống kê hệ thống (doanh thu, số lượng giao dịch, người dùng mới).
    - Quản lý khiếu nại và phản hồi từ người dùng.
  - **Trang đăng bán sản phẩm:** Cho phép người bán upload nhiều ảnh và video sản phẩm.
  - **Trang quản lý giao dịch:** Cho phép người bán upload ảnh/video đóng gói khi giao hàng, người mua upload video unbox khi nhận hàng.
- **Database (MongoDB Atlas):**
  - Collection: users, products, offers, transactions, notifications, complaints.
  - Lưu trữ đường dẫn hoặc metadata của ảnh/video liên quan đến sản phẩm, giao dịch (đóng gói, unbox).

### Thiết kế chi tiết Database (MongoDB)

**users**
- _id: ObjectId
- email: String (unique)
- password: String (hash)
- role: String ('buyer', 'seller', 'admin')
- name: String
- address: Object (street, city, state, postalCode, country)
- phone: String
- isVerified: Boolean
- blockStatus: Boolean
- createdAt, updatedAt: Timestamp

**products**
- _id: ObjectId
- sellerId: ObjectId (ref users)
- title: String
- description: String
- category: String
- price: Number
- allowBargain: Boolean
- bargainPriceMin, bargainPriceMax: Number
- media: Array of { url, type ('image'/'video'), uploadedAt }
- status: String ('pending', 'active', 'sold', 'hidden', 'deleted')
- createdAt, updatedAt: Timestamp

**offers**
- _id: ObjectId
- productId: ObjectId (ref products)
- buyerId: ObjectId (ref users)
- offeredPrice: Number
- status: String ('pending', 'accepted', 'rejected', 'expired', 'cancelled')
- expiresAt: Timestamp
- createdAt, updatedAt: Timestamp

**transactions**
- _id: ObjectId
- productId, buyerId, sellerId: ObjectId
- offerId: ObjectId (nullable)
- finalPrice: Number
- platformFee: Number
- paymentStatus: String ('pending', 'paid', 'refunded')
- status: String ('awaiting_payment', 'packaging', 'shipped', 'delivered', 'completed', 'cancelled', 'dispute')
- shippingAddress: Object (snapshot)
- proofMedia: Array of { url, type ('packaging_image', 'packaging_video', 'unboxing_video'), uploaderRole, uploadedAt }
- buyerConfirmationTimestamp: Timestamp
- sellerPayoutTimestamp: Timestamp
- createdAt, updatedAt: Timestamp

**notifications**
- _id: ObjectId
- userId: ObjectId
- title: String
- message: String
- type: String
- relatedResource: { type, id }
- isRead: Boolean
- createdAt: Timestamp

**complaints**
- _id: ObjectId
- transactionId: ObjectId
- complainantId: ObjectId
- respondentId: ObjectId
- reason: String
- description: String
- evidenceMedia: Array of { url, type, uploadedAt }
- status: String ('open', 'under_review', 'resolved_buyer', 'resolved_seller', 'closed')
- resolutionDetails: String
- adminId: ObjectId
- createdAt, updatedAt: Timestamp

**reviews** (mở rộng)
- _id: ObjectId
- productId: ObjectId
- reviewerId: ObjectId
- rating: Number
- comment: String
- createdAt: Timestamp

**messages** (mở rộng/chat)
- _id: ObjectId
- fromUserId: ObjectId
- toUserId: ObjectId
- content: String
- relatedProductId: ObjectId (optional)
- createdAt: Timestamp

**4. Quy trình nghiệp vụ chính:**

1. Người bán đăng sản phẩm, thiết lập giá và cho phép trả giá (nếu muốn).
2. Người mua xem sản phẩm, gửi đề nghị trả giá (nếu được phép).
3. Người bán nhận email, xác nhận hoặc từ chối giá.
4. Nếu đồng ý, người mua nhận email xác nhận, tiến hành thanh toán qua MoMo.
5. Sàn giữ tiền, cập nhật trạng thái giao dịch.
6. Người mua xác nhận đã nhận hàng, có thể upload video unbox để xác nhận tình trạng sản phẩm. Nếu có khiếu nại, hệ thống sử dụng ảnh/video làm bằng chứng hỗ trợ xử lý tranh chấp.

**5. Mở rộng:**

- Đánh giá sản phẩm/người bán.
- Chat trực tiếp giữa người mua và người bán.
- Thống kê doanh thu, số lượng giao dịch.

**6. Lưu ý triển khai:**

- Bảo mật thông tin người dùng, xác thực JWT.
- Xử lý trạng thái giao dịch rõ ràng, tránh gian lận.
- Tích hợp email và MoMo cần đăng ký tài khoản dịch vụ.


