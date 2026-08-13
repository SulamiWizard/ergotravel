ErgoTravel
====

![ErgoTravel](https://i.imgur.com/H9t6Q7b.png)

## Symlink to qmk directory

```sh
ln -s <path-to-this-dir> ~/qmk_firmware/keyboards/ergotravel/keymaps/yourname
```

## Flashing

```sh
qmk flash -kb ergotravel -km timeless-qwerty -bl avrdude-split-right
qmk flash -kb ergotravel -km timeless-qwerty -bl avrdude-split-left
```

## Advanced configuration and fine tuning

Here is how to troubleshoot and tune:

Noticeable delay when tapping HRMs: Increase FLOW_TAP_TERM.

- False negatives (same-hand): Reduce `TAPPING_TERM` (or disable Chordal Hold)

- False negatives (cross-hand): Reduce `FLOW_TAP_TERM`

- False positives (same-hand): Increase `TAPPING_TERM`

- False positives (cross-hand): Increase `FLOW_TAP_TERM`

In the above, "false positives" mean triggering modifiers accidentally, while a "false negatives" mean failing to trigger modifiers when they are desired:

Additionally, all options are per-key configurable (see TAPPING_TERM_PER_KEY, PERMISSIVE_HOLD_PER_KEY, get_speculative_hold()), or even more finely, are per-chord configurable. Personally, I find it helpful to:

- Set shorter timeouts on my Shift HRMs, through TAPPING_TERM_PER_KEY + the get_tapping_term() callback. I use HRMs for shifting, rather than a thumb shift key like urob does.

- Enable Flow Tap only on my pinky HRMs, through get_flow_tap_term().

- For Chordal Hold, use the get_chordal_hold() callback to define a few exceptions to the "opposite hands" rule.

Hopefully something in this guide has been helpful to you. Enjoy your HRMs!

QMK documentation references:

- [Tapping term](https://docs.qmk.fm/tap_hold#tapping-term)

- [Permissive Hold](https://docs.qmk.fm/tap_hold#permissive-hold)

- [Flow Tap](https://docs.qmk.fm/tap_hold#flow-tap)

- [Chordal Hold](https://docs.qmk.fm/tap_hold#chordal-hold)

- [Speculative Hold](https://docs.qmk.fm/tap_hold#speculative-hold)

Related links:

- [my keymap – an example implementation](https://github.com/getreuer/qmk-keymap)

- [Home row mods are hard to use](https://getreuer.info/posts/keyboards/faqs/index.html#home-row-mods-are-hard-to-use)

- [A guide to home row mods](https://precondition.github.io/home-row-mods)

- [Layout Buffet – Home-row mods](https://blog.zsa.io/layout-buffet-home-row-mods/)

[copied from this reddit post:](https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/urobs_zmk_timeless_home_row_mods_ported_to_native/)
