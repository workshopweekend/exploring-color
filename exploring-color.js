$(function() {
  $('pre').wrap('<div class="wrapped-code hidden"></div>');
  $('.wrapped-code').prepend('<span class="show-code-link">Show code &raquo;</span><span class="hide-code-link">&times;</span>');
})