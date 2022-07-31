var vertex = 
`void main()
{
  gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
  gl_PointSize = 10.0;                    
}`;

var fragment =
`void main() 
{
  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); 
}`;

function main() 
{
  canvas = document.getElementById('0');
  gl = canvas.getContext('webgl');

  vertex_shader = gl.createShader(gl.VERTEX_SHADER);
  gl.shaderSource(vertex_shader, vertex);
  gl.compileShader(vertex_shader);
  fragment_shader = gl.createShader(gl.FRAGMENT_SHADER);
  gl.shaderSource(fragment_shader, fragment);
  gl.compileShader(fragment_shader);
  program = gl.createProgram();
  gl.attachShader(program, vertex_shader);
  gl.attachShader(program, fragment_shader);
  gl.linkProgram(program);
  gl.useProgram(program);
  gl.program = program;

  gl.clearColor(0.0, 0.0, 0.0, 1.0);   /* specify the color for clearing <canvas> */
  gl.clear(gl.COLOR_BUFFER_BIT); /* clear canvas */
  gl.drawArrays(gl.POINTS, 0, 1); /* draw a point */
}
