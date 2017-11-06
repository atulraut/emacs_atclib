;; Atul's emacs
;; make it easy on eyes first ...
(set-foreground-color "gray")
(set-background-color "black")

(require 'xcscope)

;; where my elisp stuff is
(setq load-path (cons "D:/emacs-23.3/site-lisp" load-path))

(defun load-directory (dir)
        (let ((load-it (lambda (f)
				(load-file (concat (file-name-as-directory dir) f)))
				))
		(mapc load-it (directory-files dir nil "\\.el$"))))
    (load-directory "~/home/atul/bin/")
(load "/home/atul/bin/tbemail.el")

(load "/home/atul/bin/tbemail.el")

(load "/home/atul/.emacs.d/init.el")

;; syntax highlighting
(global-font-lock-mode t)
(setq font-lock-maximum-decoration t)
(setq font-lock-maximum-size 262144)

;; show me line and column nos
(line-number-mode t)
(column-number-mode t)
;; show current function too
;;(show-func-mode t)

;; none of these please
(scroll-bar-mode nil)
(tool-bar-mode nil)
(menu-bar-mode nil)

(add-hook 'c-mode-common-hook
	      (lambda ()
		      (when (derived-mode-p 'c-mode 'c++-mode 'java-mode 'asm-mode)
			  (ggtags-mode 1))))

(require 'package)
(add-to-list 'package-archives
	            '("melpa" . "http://melpa.milkbox.net/packages/") t)

(add-hook 'c-mode-common-hook
	      (lambda ()
		      (when (derived-mode-p 'c-mode 'c++-mode 'java-mode 'asm-mode)
			  (ggtags-mode 1))))


(add-hook 'dired-mode-hook 'ggtags-mode)
(setq ido-enable-flex-matching t)
(setq ido-everywhere t)
(ido-mode 1)

;; save and restore my buffers every time
(desktop-save-mode 1)

;; way better buffer-switching ...
(ido-mode t)

;; c mode customizations
(cwarn-mode t)
(setq c-default-style "linux")
(which-func-mode t)
;;(hide-ifdefs t)

;; cscope - i don't use etags any more ...
(require 'xcscope)
(setq cscope-do-not-update-database t)

;; compilation
(set-default 'compile-command "D:/bin/build.bat")
(setq compilation-scroll-output t)
(setq compilation-read-command nil)

;; clearcase
(require 'clearcase)

;; show date and time in mode-line
(setq display-time-day-and-date t )
;;(setq display-time-24hr-format t)
(display-time)

;; comment out "#if 0" blocks in c mode
;; very handy and saves a ton of cursing
;; this fn from http://stackoverflow.com/questions/4549015/in-c-c-mode-in-emacs-change-face-of-code-in-if-0-endif-block-to-comment-fa

(defun my-c-mode-font-lock-if0 (limit)
  (save-restriction
    (widen)
    (save-excursion
      (goto-char (point-min))
      (let ((depth 0) str start start-depth)
        (while (re-search-forward "^\\s-*#\\s-*\\(if\\|else\\|endif\\)" limit 'move)
          (setq str (match-string 1))
          (if (string= str "if")
              (progn
                (setq depth (1+ depth))
                (when (and (null start) (looking-at "\\s-+0"))
                  (setq start (match-end 0)
                        start-depth depth)))
            (when (and start (= depth start-depth))
              (c-put-font-lock-face start (match-beginning 0) 'font-lock-comment-face)
              (setq start nil))
            (when (string= str "endif")
              (setq depth (1- depth)))))
        (when (and start (> depth 0))
          (c-put-font-lock-face start (point) 'font-lock-comment-face)))))
  nil)

(defun my-c-mode-common-hook ()
  (font-lock-add-keywords
   nil
   '((my-c-mode-font-lock-if0 (0 font-lock-comment-face prepend))) 'add-to-end))

(add-hook 'c-mode-common-hook 'my-c-mode-common-hook)

(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(clearcase-checkout-arguments (quote ("-unreserved"))))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )

(require 'xcscope)
(setq load-path (cons "~/bin" load-path))

(defun eshell-here ()
  "Opens up a new shell in the directory associated with the
current buffer's file. The eshell is renamed to match that
directory to make multiple eshell windows easier."
  (interactive)
  (let* ((parent (if (buffer-file-name)
                     (file-name-directory (buffer-file-name))
                   default-directory))
         (height (/ (window-total-height) 3))
         (name   (car (last (split-string parent "/" t)))))
    (split-window-vertically (- height))
    (other-window 1)
    (eshell "new")
    (rename-buffer (concat "*eshell: " name "*"))

    (insert (concat "ls"))
    (eshell-send-input)))

(global-set-key (kbd "C-!") 'eshell-here)


(defun eshell/x ()
  (insert "exit")
  (eshell-send-input)
  (delete-window))	
(put 'upcase-region 'disabled nil)

;;https://truongtx.me/2013/03/10/ecb-emacs-code-browser
;;https://truongtx.me/2013/01/07/emacs-package-manager
(require 'package)
(dolist (source '(("marmalade" . "http://marmalade-repo.org/packages/")
		                    ("elpa" . "http://tromey.com/elpa/")
              ;; TODO: Maybe, use this after emacs24 is released
	      ;;                   ;; (development versions of packages)
                     ("melpa" . "http://melpa.milkbox.net/packages/")
                                                       ))
        (add-to-list 'package-archives source t))
(package-initialize)

(require 'ecb)
(require 'ecb-autoloads)

(setq ecb-layout-name "left3")

(setq ecb-show-sources-in-directories-buffer 'always)

(setq ecb-compile-window-height 12)
;;; activate and deactivate ecb
(global-set-key (kbd "C-x C-;") 'ecb-activate)
(global-set-key (kbd "C-x C-'") 'ecb-deactivate)
;;; show/hide ecb window
(global-set-key (kbd "C-;") 'ecb-show-ecb-windows)
(global-set-key (kbd "C-'") 'ecb-hide-ecb-windows)
;;; quick navigation between ecb windows
(global-set-key (kbd "C-)") 'ecb-goto-window-edit1)
(global-set-key (kbd "C-!") 'ecb-goto-window-directories)
(global-set-key (kbd "C-@") 'ecb-goto-window-sources)
(global-set-key (kbd "C-#") 'ecb-goto-window-methods)
(global-set-key (kbd "C-$") 'ecb-goto-window-compilation)

;;; replacement for built-in ecb-deactive, ecb-hide-ecb-windows and
;;; ;;; ecb-show-ecb-windows functions
;;; ;;; since they hide/deactive ecb but not restore the old windows for me
(defun tmtxt/ecb-deactivate ()
  "deactive ecb and then split emacs into 2 windows that contain 2 most recent buffers"
  (interactive)
  (ecb-deactivate)
  (split-window-right)
  (switch-to-next-buffer)
  (other-window 1))
(defun tmtxt/ecb-hide-ecb-windows ()
    "hide ecb and then split emacs into 2 windows that contain 2 most recent buffers"
      (interactive)
        (ecb-hide-ecb-windows)
	  (split-window-right)
	    (switch-to-next-buffer)
	      (other-window 1))
(defun tmtxt/ecb-show-ecb-windows ()
    "show ecb windows and then delete all other windows except the current one"
      (interactive)
        (ecb-show-ecb-windows)
	  (delete-other-windows))

(global-set-key (kbd "C-x C-'") 'tmtxt/ecb-deactivate)
(global-set-key (kbd "C-;") 'tmtxt/ecb-show-ecb-windows)
(global-set-key (kbd "C-'") 'tmtxt/ecb-hide-ecb-windows)
