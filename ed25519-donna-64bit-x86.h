#if defined(ED25519_GCC_64BIT_CHOOSE)

#define HAVE_GE25519_SCALARMULT_BASE_CHOOSE_NIELS

static void
ge25519_scalarmult_base_choose_niels(ge25519_niels *t, const ge25519_niels table[256], uint32_t pos, signed char b) {
	uint64_t sign = (uint64_t)((unsigned char)b >> 7);
	uint64_t mask = ~(sign - 1);
	uint64_t u = (b + mask) ^ mask;
	__asm__ __volatile__ (
		/* ysubx */
		"movq $1, %%r8        \n"
		"xorq %%r9, %%r9      \n"
		"xorq %%r10, %%r10    \n"
		"xorq %%r11, %%r11    \n"
		"xorq %%r12, %%r12    \n"

		/* xaddy */
		"movq $1, %%r13       \n"
		"xorq %%r14, %%r14    \n"
		"xorq %%r15, %%r15    \n"
		"xorq %%rcx, %%rcx    \n"
		"xorq %%rdi, %%rdi    \n"

		/* 1 */
		"cmpq $1, %0          \n"
		"movq 0(%2), %%rax    \n"
		"cmove %%rax, %%r8    \n"
		"movq 8(%2), %%rax    \n"
		"cmove %%rax, %%r9    \n"
		"movq 16(%2), %%rax   \n"
		"cmove %%rax, %%r10   \n"
		"movq 24(%2), %%rax   \n"
		"cmove %%rax, %%r11   \n"
		"movq 32(%2), %%rax   \n"
		"cmove %%rax, %%r12   \n"
		"movq 40(%2), %%rax   \n"
		"cmove %%rax, %%r13   \n"
		"movq 48(%2), %%rax   \n"
		"cmove %%rax, %%r14   \n"
		"movq 56(%2), %%rax   \n"
		"cmove %%rax, %%r15   \n"
		"movq 64(%2), %%rax   \n"
		"cmove %%rax, %%rcx   \n"
		"movq 72(%2), %%rax   \n"
		"cmove %%rax, %%rdi   \n"

		/* 2 */
		"cmpq $2, %0          \n"
		"movq 120(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 128(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 136(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 144(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 152(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"
		"movq 160(%2), %%rax  \n"
		"cmove %%rax, %%r13   \n"
		"movq 168(%2), %%rax  \n"
		"cmove %%rax, %%r14   \n"
		"movq 176(%2), %%rax  \n"
		"cmove %%rax, %%r15   \n"
		"movq 184(%2), %%rax  \n"
		"cmove %%rax, %%rcx   \n"
		"movq 192(%2), %%rax  \n"
		"cmove %%rax, %%rdi   \n"

		/* 3 */
		"cmpq $3, %0          \n"
		"movq 240(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 248(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 256(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 264(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 272(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"
		"movq 280(%2), %%rax  \n"
		"cmove %%rax, %%r13   \n"
		"movq 288(%2), %%rax  \n"
		"cmove %%rax, %%r14   \n"
		"movq 296(%2), %%rax  \n"
		"cmove %%rax, %%r15   \n"
		"movq 304(%2), %%rax  \n"
		"cmove %%rax, %%rcx   \n"
		"movq 312(%2), %%rax  \n"
		"cmove %%rax, %%rdi   \n"

		/* 4 */
		"cmpq $4, %0          \n"
		"movq 360(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 368(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 376(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 384(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 392(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"
		"movq 400(%2), %%rax  \n"
		"cmove %%rax, %%r13   \n"
		"movq 408(%2), %%rax  \n"
		"cmove %%rax, %%r14   \n"
		"movq 416(%2), %%rax  \n"
		"cmove %%rax, %%r15   \n"
		"movq 424(%2), %%rax  \n"
		"cmove %%rax, %%rcx   \n"
		"movq 432(%2), %%rax  \n"
		"cmove %%rax, %%rdi   \n"

		/* 5 */
		"cmpq $5, %0          \n"
		"movq 480(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 488(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 496(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 504(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 512(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"
		"movq 520(%2), %%rax  \n"
		"cmove %%rax, %%r13   \n"
		"movq 528(%2), %%rax  \n"
		"cmove %%rax, %%r14   \n"
		"movq 536(%2), %%rax  \n"
		"cmove %%rax, %%r15   \n"
		"movq 544(%2), %%rax  \n"
		"cmove %%rax, %%rcx   \n"
		"movq 552(%2), %%rax  \n"
		"cmove %%rax, %%rdi   \n"

		/* 6 */
		"cmpq $6, %0          \n"
		"movq 600(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 608(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 616(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 624(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 632(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"
		"movq 640(%2), %%rax  \n"
		"cmove %%rax, %%r13   \n"
		"movq 648(%2), %%rax  \n"
		"cmove %%rax, %%r14   \n"
		"movq 656(%2), %%rax  \n"
		"cmove %%rax, %%r15   \n"
		"movq 664(%2), %%rax  \n"
		"cmove %%rax, %%rcx   \n"
		"movq 672(%2), %%rax  \n"
		"cmove %%rax, %%rdi   \n"

		/* 7 */
		"cmpq $7, %0          \n"
		"movq 720(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 728(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 736(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 744(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 752(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"
		"movq 760(%2), %%rax  \n"
		"cmove %%rax, %%r13   \n"
		"movq 768(%2), %%rax  \n"
		"cmove %%rax, %%r14   \n"
		"movq 776(%2), %%rax  \n"
		"cmove %%rax, %%r15   \n"
		"movq 784(%2), %%rax  \n"
		"cmove %%rax, %%rcx   \n"
		"movq 792(%2), %%rax  \n"
		"cmove %%rax, %%rdi   \n"

		/* 8 */
		"cmpq $8, %0          \n"
		"movq 840(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 848(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 856(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 864(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 872(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"
		"movq 880(%2), %%rax  \n"
		"cmove %%rax, %%r13   \n"
		"movq 888(%2), %%rax  \n"
		"cmove %%rax, %%r14   \n"
		"movq 896(%2), %%rax  \n"
		"cmove %%rax, %%r15   \n"
		"movq 904(%2), %%rax  \n"
		"cmove %%rax, %%rcx   \n"
		"movq 912(%2), %%rax  \n"
		"cmove %%rax, %%rdi   \n"

		/* if (sign) swap(ysubx, xaddy) */
		"cmpq $0, %1          \n"
		"movq %%r8, %%rax     \n"
		"cmovl %%r13, %%r8    \n"
		"cmovl %%rax, %%r13   \n"
		"movq %%r9, %%rax     \n"
		"cmovl %%r14, %%r9    \n"
		"cmovl %%rax, %%r14   \n"
		"movq %%r10, %%rax    \n"
		"cmovl %%r15, %%r10   \n"
		"cmovl %%rax, %%r15   \n"
		"movq %%r11, %%rax    \n"
		"cmovl %%rcx, %%r11   \n"
		"cmovl %%rax, %%rcx   \n"
		"movq %%r12, %%rax    \n"
		"cmovl %%rdi, %%r12   \n"
		"cmovl %%rax, %%rdi   \n"

		/* store ysubx, xaddy */
		"movq %%r8, 0(%3)     \n"
		"movq %%r9, 8(%3)     \n"
		"movq %%r10, 16(%3)   \n"
		"movq %%r11, 24(%3)   \n"
		"movq %%r12, 32(%3)   \n"
		"movq %%r13, 40(%3)   \n"
		"movq %%r14, 48(%3)   \n"
		"movq %%r15, 56(%3)   \n"
		"movq %%rcx, 64(%3)   \n"
		"movq %%rdi, 72(%3)   \n"

		/* t2d */
		"xorq %%r8, %%r8      \n"
		"xorq %%r9, %%r9      \n"
		"xorq %%r10, %%r10    \n"
		"xorq %%r11, %%r11    \n"
		"xorq %%r12, %%r12    \n"

		/* 1 */
		"cmpq $1, %0          \n"
		"movq 80(%2), %%rax   \n"
		"cmove %%rax, %%r8    \n"
		"movq 88(%2), %%rax   \n"
		"cmove %%rax, %%r9    \n"
		"movq 96(%2), %%rax   \n"
		"cmove %%rax, %%r10   \n"
		"movq 104(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 112(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"

		/* 2 */
		"cmpq $2, %0          \n"
		"movq 200(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 208(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 216(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 224(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 232(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"

		/* 3 */
		"cmpq $3, %0          \n"
		"movq 320(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 328(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 336(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 344(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 352(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"

		/* 4 */
		"cmpq $4, %0          \n"
		"movq 440(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 448(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 456(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 464(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 472(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"

		/* 5 */
		"cmpq $5, %0          \n"
		"movq 560(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 568(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 576(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 584(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 592(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"

		/* 6 */
		"cmpq $6, %0          \n"
		"movq 680(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 688(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 696(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 704(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 712(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"

		/* 7 */
		"cmpq $7, %0          \n"
		"movq 800(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 808(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 816(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 824(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 832(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"

		/* 8 */
		"cmpq $8, %0          \n"
		"movq 920(%2), %%rax  \n"
		"cmove %%rax, %%r8    \n"
		"movq 928(%2), %%rax  \n"
		"cmove %%rax, %%r9    \n"
		"movq 936(%2), %%rax  \n"
		"cmove %%rax, %%r10   \n"
		"movq 944(%2), %%rax  \n"
		"cmove %%rax, %%r11   \n"
		"movq 952(%2), %%rax  \n"
		"cmove %%rax, %%r12   \n"

		/* -t2d */
		"movq $0xfffffffffffda, %%r13 \n"
		"movq $0xffffffffffffe, %%r14 \n"
		"movq %%r14, %%r15            \n"
		"movq %%r14, %%rcx            \n"
		"movq %%r14, %%rdi            \n"
		"subq %%r8, %%r13             \n"
		"subq %%r9, %%r14             \n"
		"subq %%r10, %%r15            \n"
		"subq %%r11, %%rcx            \n"
		"subq %%r12, %%rdi            \n"
		"cmpq $0, %1                  \n"
		"cmovl %%r13, %%r8            \n"
		"cmovl %%r14, %%r9            \n"
		"cmovl %%r15, %%r10           \n"
		"cmovl %%rcx, %%r11           \n"
		"cmovl %%rdi, %%r12           \n"

		/* store t2d */
		"movq %%r8, 80(%3)   \n"
		"movq %%r9, 88(%3)   \n"
		"movq %%r10, 96(%3)  \n"
		"movq %%r11, 104(%3) \n"
		"movq %%r12, 112(%3) \n"
		:
		: "r"(u), "r"((int64_t)b), "r"(&table[pos * 8]), "r"(t) /* %0 = u, %1 = b, %2 = table, %3 = t */
		: "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15", "%rcx", "%rdi", "%rax"
	);
}

#endif /* defined(ED25519_GCC_64BIT_CHOOSE) */

