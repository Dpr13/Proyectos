using UnityEngine;
using System.Collections;

public class camera_orbit : MonoBehaviour
{

    public Transform target;
    private float speedMod = 3.0f;
    private Vector3 point;

    void Start()
    {
        point = target.transform.position;
        transform.LookAt(point);
    }

    void Update()
    {
        var direccion = target.position - transform.position;
        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.RotateAround(point, Vector3.up, 20 * Time.deltaTime * speedMod);
        }
        else if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.RotateAround(point, Vector3.up, -20 * Time.deltaTime * speedMod);
        }

        if (Input.GetKey(KeyCode.UpArrow) && (direccion.magnitude > 0.4))
        {
            transform.Translate(Vector3.forward * 3.0f * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.DownArrow))
        {
            transform.Translate(Vector3.forward * -3.0f * Time.deltaTime);
        }

    }
}
