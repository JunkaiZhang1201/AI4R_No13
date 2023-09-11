function clearCanvas(canvas_id)
{
    var canvas = document.getElementById(canvas_id);

    var ctx = canvas.getContext("2d");

    ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);
}

function clearCanvasPortion(canvas_id,x,y,width,height)
{

    var canvas = document.getElementById(canvas_id);

    var ctx = canvas.getContext("2d");

    ctx.clearRect(x, y, width, height);

}

function drawSinglePoint(canvas_id, u, v, point_size, point_shape)
{
		var ctx = document.getElementById("lineDetectorCanvas").getContext("2d");

		ctx.fillStyle = "#6ba4ff";
		ctx.beginPath(); //Start path
        var u_for_plot = u;
        var v_for_plot = v;
		ctx.arc(u_for_plot, v_for_plot, point_size, 0, Math.PI * 2, true); // Draw a point using the arc function of the canvas with a point structure.
		ctx.fill(); // Close the path and fill.
}

function drawPoints(canvas_id, list_of_points, image_width, image_height)
{
    var ctx = document.getElementById("lineDetectorCanvas").getContext("2d");

    // Display the resolution of the canvas
    //console.log("ctx.canvas.width = " + ctx.canvas.width);
    //console.log("ctx.canvas.height = " + ctx.canvas.height);

    // Display the dimensions of the what is visible in the browser
    //console.log("ctx.canvas.clientWidth = " + ctx.canvas.clientWidth);
    //console.log("ctx.canvas.clientHeight = " + ctx.canvas.clientHeight);

    // Check if the resolution of the canvas matches the image dimensions supplied
    if ((ctx.canvas.width != image_width) || (ctx.canvas.height != image_height))
    {
        // Set the size
        ctx.canvas.width = image_width;
        ctx.canvas.height = image_height;
    }

    // // Draw a rectangle for the image size
    // // > Start a new path
    // ctx.beginPath();
    // ctx.moveTo(1,1);
    // // > Set the appearance of the path
    // ctx.lineWidth = 4;
    // ctx.strokeStyle = "#6ba4ff";
    // ctx.lineJoin = "round";
    // ctx.lineCap = "round";
    // // > Draw the path
    // ctx.lineTo(1,image_height-1);
    // ctx.lineTo(image_width-1,image_height-1);
    // ctx.lineTo(image_width-1,1);
    // ctx.lineTo(1,1);
    // ctx.stroke()

    // Get the value for the dot size to draw
    var size_selector = document.getElementById("sizeOfPointsOnCanvas");
    var point_size = size_selector.value;

    // Get the shape to draw
    var point_shape = "circle";

    if (list_of_points.length > 0)
    {
        for (var i = 0; i < list_of_points.length; i++) {
            drawSinglePoint(canvas_id,list_of_points[i].u,list_of_points[i].v,point_size,point_shape)
        }
    }
}

function drawLineThroughPoints(canvas_id, list_of_points, line_width)
{
    var ctx = document.getElementById("lineDetectorCanvas").getContext("2d");
    if (list_of_points.length > 0)
    {
        // Start a new path
        ctx.beginPath();
        ctx.moveTo(list_of_points[0].u, list_of_points[0].v);
        // Set the appearance of the path
        ctx.lineWidth = 2;
        ctx.strokeStyle = "#6ba4ff";
        ctx.lineJoin = "round";
        ctx.lineCap = "round";
        // Draw the path
        for (var i = 1; i < list_of_points.length; i++) {
            ctx.lineTo(Math.round(list_of_points[i].u), Math.round(list_of_points[i].v));
        }
        ctx.stroke()
    }
}