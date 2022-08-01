vertex =
`attribute vec4 a_Position;
void main()
{
  gl_Position = a_Position;
  gl_PointSize = 10.0;
}`;

fragment =
`void main() 
{
  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}`;

function main() 
{
  canvas = document.getElementById('click point');
  gl = canvas.getContext('webgl');
  shader_init(gl, vertex, fragment);
  a_Position = gl.getAttribLocation(gl.program, 'a_Position');
  canvas.onmousedown = function(ev){ click(ev, gl, canvas, a_Position); }; /* register function (event handler) to be called on a mouse press */
  gl.clearColor(0.0, 0.0, 0.0, 1.0);
  gl.clear(gl.COLOR_BUFFER_BIT);
}

g_points = []; /* array for position of a mouse press */
function click(ev, gl, canvas, a_Position) 
{
  x = ev.clientX;
  y = ev.clientY; /* mouse pointer coordinate */
  rect = ev.target.getBoundingClientRect();
  x = ((x - rect.left) - canvas.width / 2) / (canvas.width / 2);
  y = (canvas.height / 2 - (y - rect.top)) / (canvas.height / 2);
  g_points.push(x); g_points.push(y);
  gl.clear(gl.COLOR_BUFFER_BIT);
  for(i = 0; i < g_points.length; i += 2) 
  {
    gl.vertexAttrib3f(a_Position, g_points[i], g_points[i + 1], 0.0); /* pass position of a point to a_Position variable */
    gl.drawArrays(gl.POINTS, 0, 1);
  }
}
