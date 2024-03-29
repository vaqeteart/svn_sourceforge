http://cache.baidu.com/c?m=9d78d513d99d1af31fa7837e7c508427404381132bd0a4027ea4d20ed3230a07506793ac57260777d9d20a6716d84e48adb0687d6d4566f58cc9fb57c0e1c93f2fff77672b4ac15612a448f2945b739a70cd07eaa404b7e4ad678ef59484804959ca04057bd0f18f0e0240ca3cf61536e1f59e4f465410edfa3012a51f2877&p=ce3fcf15d9c044f90aabc7710c5e&user=baidu
摘自linux-2.6.24.3内核文件<linux/sched.h>

struct task_struct {
　　volatile long state; /* -1 unrunnable, 0 runnable, >0 stopped */
　　void *stack;
　　atomic_t usage;
　　unsigned int flags; /* per process flags, defined below */
　　unsigned int ptrace;

　　int lock_depth; /* BKL lock depth */

#ifdef CONFIG_SMP
#ifdef __ARCH_WANT_UNLOCKED_CTXSW
　　int oncpu;
#endif
#endif

　　int prio, static_prio, normal_prio;
　　struct list_head run_list;
　　const struct sched_class *sched_class;
　　struct sched_entity se;

#ifdef CONFIG_PREEMPT_NOTIFIERS
　　/* list of struct preempt_notifier: */
　　struct hlist_head preempt_notifiers;
#endif

　　unsigned short ioprio;
　　/*
　　* fpu_counter contains the number of consecutive context switches
　　* that the FPU is used. If this is over a threshold, the lazy fpu
　　* saving becomes unlazy to save the trap. This is an unsigned char
　　* so that after 256 times the counter wraps and the behavior turns
　　* lazy again; this to deal with bursty apps that only use FPU for
　　* a short time
　　*/
　　unsigned char fpu_counter;
　　s8 oomkilladj; /* OOM kill score adjustment (bit shift). */
#ifdef CONFIG_BLK_DEV_IO_TRACE
　　unsigned int btrace_seq;
#endif

　　unsigned int policy;
　　cpumask_t cpus_allowed;
　　unsigned int time_slice;

#if defined(CONFIG_SCHEDSTATS) || defined(CONFIG_TASK_DELAY_ACCT)
　　struct sched_info sched_info;
#endif

　　struct list_head tasks;
　　/*
　　* ptrace_list/ptrace_children forms the list of my children
　　* that were stolen by a ptracer.
　　*/
　　struct list_head ptrace_children;
　　struct list_head ptrace_list;

　　struct mm_struct *mm, *active_mm;

　　/* task state */
　　struct linux_binfmt *binfmt;
　　int exit_state;
　　int exit_code, exit_signal;
　　int pdeath_signal; /* The signal sent when the parent dies */
　　/* ??? */
　　unsigned int personality;
　　unsigned did_exec:1;
　　pid_t pid;
　　pid_t tgid;

#ifdef CONFIG_CC_STACKPROTECTOR
/* Canary value for the -fstack-protector gcc feature */
　　unsigned long stack_canary;
#endif
　　/*
　　* pointers to (original) parent process, youngest child, younger sibling,
　　* older sibling, respectively. (p->father can be replaced with
　　 * p->parent->pid)
　　 */
　　struct task_struct *real_parent; /* real parent process (when being debugged) */
　　struct task_struct *parent; /* parent process */
　　/*
　　* children/sibling forms the list of my children plus the
　　* tasks I'm ptracing.
　　*/
　　struct list_head children; /* list of my children */
　　struct list_head sibling; /* linkage in my parent's children list */
　　struct task_struct *group_leader; /* threadgroup leader */

　　/* PID/PID hash table linkage. */
　　struct pid_link pids[PIDTYPE_MAX];
　　struct list_head thread_group;

　　struct completion *vfork_done; /* for vfork() */
　　int __user *set_child_tid; /* CLONE_CHILD_SETTID */
　　int __user *clear_child_tid; /* CLONE_CHILD_CLEARTID */

　　unsigned int rt_priority;
　　cputime_t utime, stime, utimescaled, stimescaled;
　　cputime_t gtime;
　　cputime_t prev_utime, prev_stime;
　　unsigned long nvcsw, nivcsw; /* context switch counts */
　　struct timespec start_time; /* monotonic time */
　　struct timespec real_start_time; /* boot based time */
　　/* mm fault and swap info: this can arguably be seen as either mm-specific or thread-specific */
　　unsigned long min_flt, maj_flt;

　　cputime_t it_prof_expires, it_virt_expires;
　　unsigned long long it_sched_expires;
　　struct list_head cpu_timers[3];

　　/* process credentials */
　　uid_t uid,euid,suid,fsuid;
　　gid_t gid,egid,sgid,fsgid;
　　struct group_info *group_info;
　　kernel_cap_t   cap_effective, cap_inheritable, cap_permitted;
　　unsigned keep_capabilities:1;
　　struct user_struct *user;
#ifdef CONFIG_KEYS
　　struct key *request_key_auth; /* assumed request_key authority */
　　struct key *thread_keyring; /* keyring private to this thread */
　　unsigned char jit_keyring; /* default keyring to attach requested keys to */
#endif
　　char comm[TASK_COMM_LEN]; /* executable name excluding path
　　- access with [gs]et_task_comm (which lock
　　it with task_lock())
　　- initialized normally by flush_old_exec */
　　/* file system info */
　　int link_count, total_link_count;
#ifdef CONFIG_SYSVIPC
　　/* ipc stuff */
　　struct sysv_sem sysvsem;
#endif
　　/* CPU-specific state of this task */
　　struct thread_struct thread;
　　/* filesystem information */
　　struct fs_struct *fs;
　　/* open file information */
　　struct files_struct *files;
　　/* namespaces */
　　struct nsproxy *nsproxy;
　　/* signal handlers */
　　struct signal_struct *signal;
　　struct sighand_struct *sighand;

　　sigset_t blocked, real_blocked;
　　sigset_t saved_sigmask; /* To be restored with TIF_RESTORE_SIGMASK */
　　struct sigpending pending;

　　unsigned long sas_ss_sp;
　　size_t sas_ss_size;
　　int (*notifier)(void *priv);
　　void *notifier_data;
　　sigset_t *notifier_mask;
#ifdef CONFIG_SECURITY
　　void *security;
#endif
　　struct audit_context *audit_context;
　　seccomp_t seccomp;

　　/* Thread group tracking */
　　u32 parent_exec_id;
　　u32 self_exec_id;
　　/* Protection of (de-)allocation: mm, files, fs, tty, keyrings */
　　spinlock_t alloc_lock;

　　/* Protection of the PI data structures: */
　　spinlock_t pi_lock;

#ifdef CONFIG_RT_MUTEXES
　　/* PI waiters blocked on a rt_mutex held by this task */
　　struct plist_head pi_waiters;
　　/* Deadlock detection and priority inheritance handling */
　　struct rt_mutex_waiter *pi_blocked_on;
#endif

#ifdef CONFIG_DEBUG_MUTEXES
　　/* mutex deadlock detection */
　　struct mutex_waiter *blocked_on;
#endif
#ifdef CONFIG_TRACE_IRQFLAGS
　　unsigned int irq_events;
　　int hardirqs_enabled;
　　unsigned long hardirq_enable_ip;
　　unsigned int hardirq_enable_event;
　　unsigned long hardirq_disable_ip;
　　unsigned int hardirq_disable_event;
　　int softirqs_enabled;
　　unsigned long softirq_disable_ip;
　　unsigned int softirq_disable_event;
　　unsigned long softirq_enable_ip;
　　unsigned int softirq_enable_event;
　　int hardirq_context;
　　int softirq_context;
#endif
#ifdef CONFIG_LOCKDEP
# define MAX_LOCK_DEPTH 30UL
　　u64 curr_chain_key;
　　int lockdep_depth;
　　struct held_lock held_locks[MAX_LOCK_DEPTH];
　　unsigned int lockdep_recursion;
#endif

　　/* journalling filesystem info */
　　void *journal_info;

　　/* stacked block device info */
　　struct bio *bio_list, **bio_tail;

　　/* VM state */
　　struct reclaim_state *reclaim_state;

　　struct backing_dev_info *backing_dev_info;

　　struct io_context *io_context;

　　unsigned long ptrace_message;
　　siginfo_t *last_siginfo; /* For ptrace use. */
#ifdef CONFIG_TASK_XACCT
　　/* i/o counters(bytes read/written, #syscalls */
　　u64 rchar, wchar, syscr, syscw;
#endif
　　struct task_io_accounting ioac;
#if defined(CONFIG_TASK_XACCT)
　　u64 acct_rss_mem1; /* accumulated rss usage */
　　u64 acct_vm_mem1; /* accumulated virtual memory usage */
　　cputime_t acct_stimexpd;/* stime since last update */
#endif
#ifdef CONFIG_NUMA
　　struct mempolicy *mempolicy;
　　short il_next;
#endif
#ifdef CONFIG_CPUSETS
　　nodemask_t mems_allowed;
　　int cpuset_mems_generation;
　　int cpuset_mem_spread_rotor;
#endif
#ifdef CONFIG_CGROUPS
　　/* Control Group info protected by css_set_lock */
　　struct css_set *cgroups;
　　/* cg_list protected by css_set_lock and tsk->alloc_lock */
　　struct list_head cg_list;
#endif
#ifdef CONFIG_FUTEX
　　struct robust_list_head __user *robust_list;
#ifdef CONFIG_COMPAT
　　struct compat_robust_list_head __user *compat_robust_list;
#endif
　　struct list_head pi_state_list;
　　struct futex_pi_state *pi_state_cache;
#endif
　　atomic_t fs_excl; /* holding fs exclusive resources */
　　struct rcu_head rcu;

　　/*
　　* cache last used pipe for splice
　　*/
　　struct pipe_inode_info *splice_pipe;
#ifdef CONFIG_TASK_DELAY_ACCT
　　struct task_delay_info *delays;
#endif
#ifdef CONFIG_FAULT_INJECTION
　　int make_it_fail;
#endif
　　struct prop_local_single dirties;
};
