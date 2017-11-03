;; Atul's .emacs

;; make it easy on eyes first ...
(set-foreground-color "gray")
(set-background-color "black")

;; where my elisp stuff is
(setq load-path (cons "D:/emacs-23.3/site-lisp" load-path))
(require 'xcscope)
 
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
