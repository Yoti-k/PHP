<?php
 declare(strict_types=1);
 
 echo '<h1 style="text-align: center;">Галерея загруженных изображений</h1>';

 echo '<div class="gallery" style="display: flex; flex-wrap: nowrap;
       justify-content: space-evenly">';
 
 foreach (scandir(__DIR__) as $imgfile) {
     if (mime_content_type($imgfile) == 'image/jpeg') {
         echo '<img src="', $imgfile, '" alt="', $imgfile,
         '" width="400"></img>';
     }
 }
 
 echo '</div>';
